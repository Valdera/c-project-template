all: prepare

install_min:
	sudo apt-get install gcc g++ cmake make doxygen

install_test: install_min
	echo "Install Test Dependencies"
	pip install gcovr==7.0
	sudo apt-get install lcov

install: install_min
	sudo apt-get install git llvm pkg-config curl zip unzip tar python3-dev clang-format clang-tidy cppcheck iwyu

install_pip:
	pip install jinja2 Pygments cmake-format pre-commit

install_doc: install_min
	echo "Install Docs Dependencies"
	sudo apt-get install doxygen
	pip install jinja2 Pygments

install_conan:
	pip install conan --user

docs:
	cd docs && doxygen

dependency:
	cd build && cmake .. --graphviz=graph.dot && dot -Tpng graph.dot -o graph_deps.png

prepare:
	rm -rf build
	mkdir build
