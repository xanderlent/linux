/* SPDX-License-Identifier: GPL-2.0-only */
/* Copyright(c) 2017-2022 Intel Corporation */

#ifndef __GNA_REQUEST_H__
#define __GNA_REQUEST_H__

#include <linux/kref.h>
#include <linux/types.h>
#include <linux/workqueue.h>

#include <uapi/drm/igna_accel.h>

struct gna_device;
struct gna_gem_object;
struct drm_file;

struct gna_buffer_with_object {
	struct gna_buffer gna;
	struct gna_gem_object *gem;
};

struct gna_request {
	u64 request_id;

	struct kref refcount;

	struct drm_file *drm_f;

	struct list_head node;

	struct gna_compute_cfg compute_cfg;

	struct gna_buffer_with_object *buffer_list;
	u64 buffer_count;

	struct work_struct work;
};

int gna_validate_score_config(struct gna_compute_cfg *compute_cfg,
			struct gna_device *gna_priv);

int gna_enqueue_request(struct gna_compute_cfg *compute_cfg,
			struct drm_file *file, u64 *request_id);

void gna_request_release(struct kref *ref);

#endif // __GNA_REQUEST_H__
