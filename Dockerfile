#### docker commands

FROM python:3.6.5 AS py365

LABEL maintainer="nakashimn"

COPY ./pybind_eigen /vol/pybind_eigen

RUN set -x && \
    apt-get update && \
    apt-get upgrade -y && \
    apt-get -y install nano cmake libeigen3-dev && \
    pip install --upgrade pip && \
    pip install numpy pandas matplotlib scikit-learn openpyxl pybind11
