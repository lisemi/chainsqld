# ChainSQL 

# Use the alpine baseimage
FROM alpine:3.7
MAINTAINER HenryLu <luxiaoming@peersafe.cn>

# make sure the package repository is up to date
#RUN apk update && \
#	apk upgrade --update-cache 

# install the dependencies
RUN apk add build-base  \
			protobuf-dev  \
			boost-dev  \
			llvm5-dev  \
			llvm5-static  \
			clang-dev  \
			cmake  \
			mariadb-dev  \
			libressl-dev


#ENV CC /usr/bin/gcc
#ENV CXX /usr/bin/g++ 

WORKDIR /opt/chainsql

COPY ./src ./src
COPY ./Builds/CMake ./Builds/CMake
COPY ./doc/chainsqld-example.cfg chainsqld.cfg
COPY ./mysqlclient.pc /usr/lib/pkgconfig/
COPY ./CMakeLists.txt CMakeLists.txt

RUN cd Builds; cmake -Dtarget=clang.release.unity  ../; make chainsqld -j2


# move to root directory and strip
RUN cp ./build/clang.release.unity/chainsqld chainsqld
RUN strip chainsqld

# clean source
#RUN rm -r src

# launch chainsqld when launching the container
ENTRYPOINT ./chainsqld
#ENTRYPOINT sleep 1000