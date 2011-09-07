CC        := g++
LD        := g++

MODULES   := lib lib/components lib/Errorer lib/gameobject lib/loader lib/manager lib/templates lib/TinyXml lib/templates/components lib/templates/objects
#UNITMODS  := 
SRC_DIR   := $(MODULES)
BUILD_DIR := $(MODULES)

SRC       := $(foreach sdir,$(SRC_DIR),$(wildcard $(sdir)/*.cpp))
BUILDSRC  := main.cpp $(SRC)
UNITSRC   := unittestmain.cpp $(SRC) 
#$(foreach sdir,$(UNITMODS),$(wildcard $(sdir)/*.cpp))
OBJ       := $(patsubst %.cpp,%.o,$(BUILDSRC))
UNITOBJ   := $(patsubst %.cpp,%.o,$(BUILDSRC))
INCLUDES  := $(addprefix -I,$(SRC_DIR))

vpath %.cpp $(SRC_DIR)

define make-goal
$1/%.o: %.cpp
	$(CC) $(INCLUDES) -c $$< -o $$@
endef

.PHONY: all checkdirs clean

all: checkdirs BlockBuilder BlockBuilderCppUnit

BlockBuilder: $(OBJ)
	$(LD) $^ -o $@

BlockBuilderCppUnit: $(UNITOBJ)
	$(LD) $^ -lcppunit -o $@ 

checkdirs: $(BUILD_DIR)

$(BUILD_DIR):
	@mkdir -p $@

clean:
	@rm -rf $(OBJ)
	@rm -rf BlockBuilder
	@rm -rf BlockBuilderCppUnit



