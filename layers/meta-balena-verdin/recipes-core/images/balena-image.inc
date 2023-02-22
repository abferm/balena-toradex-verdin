IMAGE_FSTYPES:append:verdin-imx8mm = " balenaos-img"
KERNEL_IMAGETYPE:verdin-imx8mm = "Image.gz"

BALENA_BOOT_PARTITION_FILES:verdin-imx8mm = " \
    ${KERNEL_IMAGETYPE}${KERNEL_INITRAMFS}-${MACHINE}.bin:/Image.gz \
    sbc-imx8.dtb:/sbc-imx8.dtb \
    sbc-imx8-bluetooth.dtb:/sbc-imx8-bluetooth.dtb \
    sbc-imx8-lvds-dcss.dtb:/sbc-imx8-lvds-dcss.dtb \
    sbc-imx8-lvds-lcdif.dtb:/sbc-imx8-lvds-lcdif.dtb \
    sbc-imx8-dual.dtb:/sbc-imx8-dual.dtb \
    sbc-imx8-thermal.dtb:/sbc-imx8-thermal.dtb \
    sbc-imx8-m4.dtb:/sbc-imx8-m4.dtb \
"

IMAGE_INSTALL:append:verdin-imx8mm = " \
                                        imx-boot \
                                        kernel-modules \
					firmware-imx \
					firmware-imx-sdma \
					firmware-imx-epdc \
					linux-firmware-ibt \
"

IMAGE_CMD:balenaos-img:append:verdin-imx8mm () {
    dd if=${DEPLOY_DIR_IMAGE}/imx-boot-${MACHINE}-sd.bin-flash_evk of=${BALENA_RAW_IMG} conv=notrunc seek=33 bs=1K
}

