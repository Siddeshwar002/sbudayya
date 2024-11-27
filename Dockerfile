FROM ubuntu:20.04

RUN apt-get update && \
    apt-get install -y build-essential netcat socat

COPY fms.c /sbudayya/fms.c
COPY flag.txt /sbudayya/flag.txt
COPY password.txt /sbudayya/password.txt
# COPY fms /sbudayya/fms

WORKDIR /sbudayya

# RUN gcc -o fms fms.c
RUN gcc -o fms fms.c -fstack-protector-all -fPIC -pie -z relro -z now -Wl,-z,noexecstack

EXPOSE 12345

RUN mkdir /sbudayya/private && \
    chmod 700 /sbudayya/private

RUN mv /sbudayya/flag.txt /sbudayya/private/flag.txt && \
    mv /sbudayya/password.txt /sbudayya/private/password.txt

RUN chmod 400 /sbudayya/private/flag.txt && \
    chmod 400 /sbudayya/private/password.txt && \
    chmod +x /sbudayya/fms

RUN echo '#!/bin/bash\n\
    set -e\n\
    socat tcp-listen:12345,reuseaddr,fork EXEC:/sbudayya/fms,stderr' > /opt/start.sh

RUN chmod +x /opt/start.sh

RUN mkdir /challenge && \
    chmod 700 /challenge

RUN echo "{\"binary_file\":\"fms\",\"source_file\":\"fms.c\"}" > /challenge/metadata.json

RUN tar czvf /challenge/artifacts.tar.gz fms.c fms

CMD ["/opt/start.sh"]
