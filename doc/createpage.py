#!/usr/bin/python

import sys
import datetime


today = datetime.datetime.now().strftime("%d %B %Y")
#print(today)

usage="""
USAGE: python3 createpage.py page
"""
#print(sys.argv[0])
# print(type(sys.argv))
# print(str(sys.argv))
# for arg in sys.argv:
#     print(arg)

n = len(sys.argv)
if n != 2:
    print("Invalid number of command line arguments ({})\n".format(n) + usage)
    sys.exit(1)

name = sys.argv[1]

# read toc.txt
# create array from toc.txt
lines = []
with open('toc.txt', 'r') as f:
  for line in f:
    lines.append(line.rstrip())
f.close()

N = len(lines)
i = 1
pages = {}
names = []
for line in lines:
    print("{} ".format(i)+line)
    split = line.split('|')
    title = split[0].strip()
    name = split[1].strip()
    numtitle = str(i) + "-" + title
    src = name+"/"+name+".template.md"
    dest = name+".md"
    link = "[{}]({})".format(title, dest)
    numlink = "[{}]({})".format(numtitle, dest)
    page = {
        "index": i,
        "name": name,
        "title": title,
        "numtitle": numtitle,
        "src": src,
        "dest": dest,
        "link": link,
        "numlink": numlink,
        "prev": None,
        "next": None,
    }
    pages[name] = page
    names.append(name)
    i += 1


for i in range(N):
    name = names[i]
    page = pages[name]
    if (i > 0): 
        page["prev"] = pages[names[i-1]]
    if (i < N-1): 
        page["next"] = pages[names[i+1]]

#print(pages)
# print(paths)
# print(names)
# print(prevs)
# print(nexts)

footer = """
| < <br />{}  | <br />{}<br /> <img width=1000/> | > <br />{}   |
| ----------- | ----------- | ----------- |
"""

for name in pages:
    page = pages[name]
    title = page["numtitle"]
    
    prev = page["prev"]
    if prev == None: 
        prev = ""
    else:
        prev = prev["numlink"]
    
    next = page["next"]
    if next == None: 
        next = ""
    else:
        next = next["numlink"]

    myheader = """# {}

_Updated {}_

""".format(page["numtitle"], today)

    f = open(page["src"], 'r')
    body = f.read()
    f.close()

    myfooter = footer.format(prev,"Table Of Contents",next)

    # print(myheader)
    # print(body)
    # print(myfooter)
    f = open(page["dest"], "w")
    f.write(myheader+body+myfooter)
    f.close()

