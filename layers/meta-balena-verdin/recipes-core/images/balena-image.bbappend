include balena-image.inc

BALENA_BOOT_PARTITION_FILES:append:verdin-imx8mm = " \
    imx-boot-${MACHINE}-sd.bin-flash_evk:\
"

# Fixes error: packages already installed
# by kernel-image-initramfs
IMAGE_INSTALL:remove = " kernel-image"
