FROM ubuntu:22.04

WORKDIR /workdir

COPY build.sh /workdir

RUN apt-get update 
RUN apt-get install -y git
RUN apt-get install -y autoconf
RUN apt-get install -y automake
RUN apt-get install -y libtool
RUN apt-get install -y wget
RUN apt-get install -y lzip
RUN apt-get install -y build-essential
RUN apt-get install -y libssl-dev

# Make the script executable
RUN chmod +x /workdir/build.sh
RUN /workdir/build.sh

# Start an interactive bash session
CMD [ "/bin/bash" ]
