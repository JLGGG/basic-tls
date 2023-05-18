# basic-tls
Personal practice project to implement basic TLS.

## Configuration
If you want to use the basic-tls, you have to clone it from Github. You also need to have Docker in your system. After the previous requirements finish, you move to `/docker`. Next, you have to execute `docker-compose up -d` which makes the running container of the basic-tls. Finally, you can access the running container by using vscode's docker and remote tool extensions. If you want to delete the container, you have to run `docker-compose stop`.

I used Docker to make a sustainable development environment because my main PC environment is an aarch64. But, the gcc and the g++ have a few problems in the aarch64. Thus, I set up the container's environment to linux/amd64 for solving issues. I also used the docker-compose for a more comfortable setting, not a dockerfile. 

## Cryptographic Summary Materials
This section is going to summarize cryptography theories used to implement TLS.

## References
