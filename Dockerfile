FROM gcc:8

MAINTAINER Yong Wu <12fogcity@tongji.edu.cn>

RUN curl https://cmake.org/files/v3.12/cmake-3.12.1-Linux-x86_64.sh -o /tmp/curl-install.sh \
      && chmod u+x /tmp/curl-install.sh \
      && mkdir /usr/bin/cmake \
      && /tmp/curl-install.sh --skip-license --prefix=/usr/bin/cmake \
      && rm /tmp/curl-install.sh

RUN curl -s https://accellera.org/images/downloads/standards/systemc/systemc-2.3.2.tar.gz | tar xz > /dev/null

ENV PATH=/usr/bin/cmake/bin:${PATH}
ENV SYSTEMC_HOME=/systemc-2.3.2
ENV LD_LIBRARY_PATH=${SYSTEMC_HOME}/lib-linux64:${LD_LIBRARY_PATH}
ENV CXX=g++

RUN cd systemc-2.3.2 \
      && cmake -DCMAKE_CXX_STANDARD=11 -DCMAKE_BUILD_TYPE=Debug \
      && cmake --build .
