default: test

BUILD_DIR = _build

compile:
	mkdir -p $(BUILD_DIR)
	gcc src/* -o $(BUILD_DIR)/resolver

deps-travis:
	pip install --user -r requirements.txt

deps:
	pip install -r requirements.txt

test:
	psychic

clean:
	rm -r $(BUILD_DIR)
