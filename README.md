## Building C++ with Meson

1. In folder `cpp`, run `docker run -u "$(id -u)":"$(id -g)" -v /etc/passwd:/etc/passwd -v /etc/group:/etc/group -v $PWD/:/build -it --rm meson-build:latest <build mode>`

> The entrypoint accepts the last argument(s) to `docker run ...`.

> Choose between build modes: `release`, `debug`, `debugsan`, `coverage`

2. Profit 💯 
 