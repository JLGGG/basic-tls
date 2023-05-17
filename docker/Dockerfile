FROM ubuntu:latest

WORKDIR /workdir

COPY build.sh /workdir

RUN apt-get update && apt-get install -y \
    git \
    autoconf \
    automake \  
    libtool \   
    wget \
    lzip \
    build-essential \
    libssl-dev 

# Make the script executable
RUN chmod +x /workdir/build.sh
RUN /workdir/build.sh

# Start an interactive bash session
CMD [ "/bin/bash" ]
