##
# QIL
#
# @file
# @version 0.1

installbazel:
	@sudo apt-key adv --keyserver hkp://keyserver.ubuntu.com:80 --recv-keys 3D5919B448457EE0
	@curl -fsSL https://bazel.build/bazel-release.pub.gpg | gpg --dearmor > bazel-release.pub
	@sudo mv bazel-release.pub /etc/apt/trusted.gpg.d/
	@echo "deb [arch=amd64] https://storage.googleapis.com/bazel-apt stable jdk1.8" | sudo tee /etc/apt/sources.list.d/bazel.list
	@sudo apt install bazel
build:
	@touch WORKSPACE
	@export BAZEL_CXXOPTS="-std=c++14"
	@bazel build //:qil

clean:
	@rm -rf bazel-bin  bazel-out  bazel-QIL  bazel-testlogs WORKSPACE build MODULE.bazel MODULE.bazel.lock

# end
