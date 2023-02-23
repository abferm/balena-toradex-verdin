FROM balena/yocto-build-env:latest

RUN mkdir -m 0755 -p /etc/apt/keyrings
RUN curl -fsSL https://download.docker.com/linux/ubuntu/gpg | gpg --dearmor -o /etc/apt/keyrings/docker.gpg

RUN echo \
  "deb [arch=$(dpkg --print-architecture) signed-by=/etc/apt/keyrings/docker.gpg] https://download.docker.com/linux/ubuntu \
  $(lsb_release -cs) stable" | tee /etc/apt/sources.list.d/docker.list > /dev/null

RUN apt-get update && apt-get install -y docker-ce-cli

# Create build user (note hostdocker group id may be different from system to system)
RUN useradd -m -s /bin/bash -N -u 1000 build && \
  echo "build ALL=(ALL) NOPASSWD: ALL" > /etc/sudoers && \
  chmod 0440 /etc/sudoers && \
  chmod g+w /etc/passwd && \
  usermod -a -G docker build && \
  groupadd -g 1001 hostdocker && \
  usermod -a -G hostdocker build

USER build
RUN rm -f /home/build/.docker/config.json

# Yocto uses git to fetch sources... Configure git to allow cloning in any directory
RUN git config --global --add safe.directory "*"

# unset the DISTRO environment variable because it overrides the desired yocto distro
ENV DISTRO=
