/* SPDX-License-Identifier: GPL-2.0-only */
/* Copyright(c) 2017-2022 Intel Corporation */

#ifndef __GNA_DEVICE_H__
#define __GNA_DEVICE_H__

#include <drm/drm_device.h>

#include <linux/io.h>
#include <linux/types.h>

#include "gna_hw.h"

#define DRIVER_NAME		"gna"
#define DRIVER_DESC		"Intel(R) Gaussian & Neural Accelerator (Intel(R) GNA)"

#define DRIVER_MAJOR		1
#define DRIVER_MINOR		0
#define DRIVER_PATCHLEVEL	0

struct device;

struct gna_device {
	struct drm_device drm;

	/* device related resources */
	void __iomem *iobase;
	struct gna_dev_info info;
	struct gna_hw_info hw_info;
};

int gna_probe(struct device *parent, struct gna_dev_info *dev_info, void __iomem *iobase);
static inline u32 gna_reg_read(struct gna_device *gna_priv, u32 reg)
{
	return readl(gna_priv->iobase + reg);
}

#endif /* __GNA_DEVICE_H__ */
