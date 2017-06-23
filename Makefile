MAP_BASE ?= http://localhost:8000/
SOURCES = pi.cpp calc.cpp
OUTPUT_OPTIONS = \
	-s WASM=1 \
	-s EXPORTED_FUNCTIONS="['_get_pi']" \
	--shell-file pi.html.template \
	--source-map-base $(MAP_BASE) \
	-g4
OUTPUT_DIR = ./
RESULT_FILES = $(addprefix $(OUTPUT_DIR), \
	pi.html pi.js pi.wast pi.wasm pi.wasm.map \
)

build:
	emcc -std=c++11 $(SOURCES) $(OUTPUT_OPTIONS) -o $(OUTPUT_DIR)pi.html

clean:
	rm -rf $(RESULT_FILES)

.PHONY: build clean
