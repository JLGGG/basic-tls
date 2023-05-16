FROM ubuntu:latest

WORKDIR /workdir

COPY /bootstrap/build.sh /workdir

RUN apt-get update
RUN apt-get install -y git
RUN apt-get install -y autoconf automake libtool
RUN apt-get install -y wget
RUN apt-get install -y lzip
RUN apt-get install -y build-essential
RUN apt-get install -y libssl-dev

# Make the script executable
RUN chmod +x /workdir/build.sh
RUN /workdir/build.sh

# Expose the desired ports
# EXPOSE 80

# docker build . -t <name>
# docker run -p 8080:80 <name>
