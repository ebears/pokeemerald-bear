FROM ubuntu:22.04

# Install dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    binutils-arm-none-eabi \
    git \
    libpng-dev

# Copy the initial working directory from the shared volume
COPY . /pokeemerald

# Clone agbcc repository and build it
RUN git clone https://github.com/pret/agbcc \
    && cd agbcc \
    && ./build.sh \
    && ./install.sh ../pokeemerald

# Set working directory to pokeemerald
WORKDIR /pokeemerald

# Build the project
RUN make -j$(nproc)

ENTRYPOINT mkdir -p /pokeemerald/output \
    && cp pokeemerald.gba /pokeemerald/output/
