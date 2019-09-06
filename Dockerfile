# ChainSQL 

# Use the alpine baseimage
FROM alpine:3.7
MAINTAINER HenryLu <luxiaoming@peersafe.cn>

# make sure the package repository is up to date
#RUN apk update && \
#	apk upgrade --update-cache 

# install the dependencies
RUN apk add build-base  \
			protobuf  \
			protobuf-dev  \
			boost-dev  \
			scons  \
			mariadb-dev  \
			libressl-dev


#ENV CC /usr/bin/gcc
#ENV CXX /usr/bin/g++ 

#RUN mkdir -p /opt/chainsql
WORKDIR /opt/chainsql

COPY ./src ./src
COPY ./SConstruct ./
COPY ./doc/chainsqld-example.cfg chainsqld.cfg
COPY ./mysqlclient.pc /usr/lib/pkgconfig/

#RUN ls -l chainsql
# compile
RUN scons --static --enable-mysql

# move to root directory and strip
#RUN cp build/chainsqld chainsqld; strip chainsqld
RUN cp ./build/chainsqld chainsqld

RUN ldd chainsqld

# clean source
#RUN rm -r src

# launch chainsqld when launching the container
ENTRYPOINT ./chainsqld
#ENTRYPOINT sleep 1000