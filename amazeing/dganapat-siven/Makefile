# NAME = a_maze_ing
VENV = venv
PYTHON = $(VENV)/bin/python3
PIP = $(VENV)/bin/pip
MAIN = a_maze_ing.py

install: # Install dependencies
	python3 -m venv $(VENV)
	$(PIP) install --upgrade pip
	$(PIP) install mypy flake8 build
# source venv/bin/activate

build: # Build the wheel and sdist directly at the repository root
	$(PYTHON) -m build --outdir .

reinstall: build # Rebuild and reinstall the package in one command
	$(PIP) install --force-reinstall mazegen-1.0.0-py3-none-any.whl

run: # Run the project
	$(PYTHON) $(MAIN) config.txt

debug: # Run with pdb
	$(PYTHON) -m pdb $(MAIN) config.txt

clean: # Remove caches and temporary files
	find . -type d -name "__pycache__" -exec rm -rf {} +
	find . -type d -name ".pytest_cache" -exec rm -rf {} +
	find . -type f -name "*.pyc" -delete

lint: # Run required linting
	flake8 . --exclude=venv,__pycache__,.mypy_cache,tests
	mypy . \
		--warn-return-any \
		--warn-unused-ignores \
		--ignore-missing-imports \
		--disallow-untyped-defs \
		--check-untyped-defs \
		--exclude '(venv|tests)'

lint-strict: # Run strict mypy checks
	flake8 . --exclude=venv,__pycache__,.mypy_cache,tests
	mypy . --strict --exclude '(venv|tests)'

uninstall: clean
		rm -rf venv

.PHONY: install build reinstall run debug clean lint lint-strict uninstall