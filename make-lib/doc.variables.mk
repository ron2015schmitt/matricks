#############################################################
# VARIABLES
#############################################################

MAKEFILE := $(abspath $(lastword $(MAKEFILE_LIST)))

include $(DIR_MATHQ)/make-lib/style.mk
include $(DIR_MATHQ)/make-lib/variables.mk

MAKEFILE_REL := $(subst $(DIR_MATHQ)/,,$(MAKEFILE))

# Scripts
CREATE_DOC_BRANCH := $(DIR_MATHQ)/scripts/createdocbranch.py
CREATE_DOC_LEAF := $(DIR_MATHQ)/scripts/createdocleaf.py

# CHAPTERS must be defined in the "incuder" file
CHAPTER_NODE_FILES = $(addsuffix /node.json,$(CHAPTERS))
CHAPTER_BRANCHES = $(subst /,,$(MAKE_SUBDIRS))
CHAPTER_LEAVES = $(filter-out $(CHAPTER_BRANCHES),$(CHAPTERS))

LEAF_READMES = $(addsuffix /README.md,$(CHAPTER_LEAVES))
