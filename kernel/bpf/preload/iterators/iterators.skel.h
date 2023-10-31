/* SPDX-License-Identifier: (LGPL-2.1 OR BSD-2-Clause) */

/* THIS FILE IS AUTOGENERATED! */
#ifndef __ITERATORS_BPF_SKEL_H__
#define __ITERATORS_BPF_SKEL_H__

#include <stdlib.h>
#include <bpf/libbpf.h>

struct iterators_bpf {
	struct bpf_object_skeleton *skeleton;
	struct bpf_object *obj;
	struct {
		struct bpf_map *rodata;
	} maps;
	struct {
		struct bpf_program *dump_bpf_map;
		struct bpf_program *dump_bpf_prog;
	} progs;
	struct {
		struct bpf_link *dump_bpf_map;
		struct bpf_link *dump_bpf_prog;
	} links;
	struct iterators_bpf__rodata {
		char dump_bpf_map____fmt[35];
		char dump_bpf_map____fmt_1[14];
		char dump_bpf_prog____fmt[32];
		char dump_bpf_prog____fmt_2[17];
	} *rodata;
};

static void
iterators_bpf__destroy(struct iterators_bpf *obj)
{
	if (!obj)
		return;
	if (obj->skeleton)
		bpf_object__destroy_skeleton(obj->skeleton);
	free(obj);
}

static inline int
iterators_bpf__create_skeleton(struct iterators_bpf *obj);

static inline struct iterators_bpf *
iterators_bpf__open_opts(const struct bpf_object_open_opts *opts)
{
	struct iterators_bpf *obj;

	obj = (typeof(obj))calloc(1, sizeof(*obj));
	if (!obj)
		return NULL;
	if (iterators_bpf__create_skeleton(obj))
		goto err;
	if (bpf_object__open_skeleton(obj->skeleton, opts))
		goto err;

	return obj;
err:
	iterators_bpf__destroy(obj);
	return NULL;
}

static inline struct iterators_bpf *
iterators_bpf__open(void)
{
	return iterators_bpf__open_opts(NULL);
}

static inline int
iterators_bpf__load(struct iterators_bpf *obj)
{
	return bpf_object__load_skeleton(obj->skeleton);
}

static inline struct iterators_bpf *
iterators_bpf__open_and_load(void)
{
	struct iterators_bpf *obj;

	obj = iterators_bpf__open();
	if (!obj)
		return NULL;
	if (iterators_bpf__load(obj)) {
		iterators_bpf__destroy(obj);
		return NULL;
	}
	return obj;
}

static inline int
iterators_bpf__attach(struct iterators_bpf *obj)
{
	return bpf_object__attach_skeleton(obj->skeleton);
}

static inline void
iterators_bpf__detach(struct iterators_bpf *obj)
{
	return bpf_object__detach_skeleton(obj->skeleton);
}

static inline int
iterators_bpf__create_skeleton(struct iterators_bpf *obj)
{
	struct bpf_object_skeleton *s;

	s = (typeof(s))calloc(1, sizeof(*s));
	if (!s)
		return -1;
	obj->skeleton = s;

	s->sz = sizeof(*s);
	s->name = "iterators_bpf";
	s->obj = &obj->obj;

	/* maps */
	s->map_cnt = 1;
	s->map_skel_sz = sizeof(*s->maps);
	s->maps = (typeof(s->maps))calloc(s->map_cnt, s->map_skel_sz);
	if (!s->maps)
		goto err;

	s->maps[0].name = "iterator.rodata";
	s->maps[0].map = &obj->maps.rodata;
	s->maps[0].mmaped = (void **)&obj->rodata;

	/* programs */
	s->prog_cnt = 2;
	s->prog_skel_sz = sizeof(*s->progs);
	s->progs = (typeof(s->progs))calloc(s->prog_cnt, s->prog_skel_sz);
	if (!s->progs)
		goto err;

	s->progs[0].name = "dump_bpf_map";
	s->progs[0].prog = &obj->progs.dump_bpf_map;
	s->progs[0].link = &obj->links.dump_bpf_map;

	s->progs[1].name = "dump_bpf_prog";
	s->progs[1].prog = &obj->progs.dump_bpf_prog;
	s->progs[1].link = &obj->links.dump_bpf_prog;

	s->data_sz = 7128;
	s->data = (void *)"\
\x7f\x45\x4c\x46\x02\x01\x01\0\0\0\0\0\0\0\0\0\x01\0\xf7\0\x01\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x18\x18\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\x40\0\x0f\0\
\x0e\0\x79\x12\0\0\0\0\0\0\x79\x26\0\0\0\0\0\0\x79\x17\x08\0\0\0\0\0\x15\x07\
\x1a\0\0\0\0\0\x79\x21\x10\0\0\0\0\0\x55\x01\x08\0\0\0\0\0\xbf\xa4\0\0\0\0\0\0\
\x07\x04\0\0\xe8\xff\xff\xff\xbf\x61\0\0\0\0\0\0\x18\x02\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\xb7\x03\0\0\x23\0\0\0\xb7\x05\0\0\0\0\0\0\x85\0\0\0\x7e\0\0\0\x61\x71\0\
\0\0\0\0\0\x7b\x1a\xe8\xff\0\0\0\0\xb7\x01\0\0\x04\0\0\0\xbf\x72\0\0\0\0\0\0\
\x0f\x12\0\0\0\0\0\0\x7b\x2a\xf0\xff\0\0\0\0\x61\x71\x14\0\0\0\0\0\x7b\x1a\xf8\
\xff\0\0\0\0\xbf\xa4\0\0\0\0\0\0\x07\x04\0\0\xe8\xff\xff\xff\xbf\x61\0\0\0\0\0\
\0\x18\x02\0\0\x23\0\0\0\0\0\0\0\0\0\0\0\xb7\x03\0\0\x0e\0\0\0\xb7\x05\0\0\x18\
\0\0\0\x85\0\0\0\x7e\0\0\0\xb7\0\0\0\0\0\0\0\x95\0\0\0\0\0\0\0\x79\x12\0\0\0\0\
\0\0\x79\x26\0\0\0\0\0\0\x79\x11\x08\0\0\0\0\0\x15\x01\x3b\0\0\0\0\0\x79\x17\0\
\0\0\0\0\0\x79\x21\x10\0\0\0\0\0\x55\x01\x08\0\0\0\0\0\xbf\xa4\0\0\0\0\0\0\x07\
\x04\0\0\xd0\xff\xff\xff\xbf\x61\0\0\0\0\0\0\x18\x02\0\0\x31\0\0\0\0\0\0\0\0\0\
\0\0\xb7\x03\0\0\x20\0\0\0\xb7\x05\0\0\0\0\0\0\x85\0\0\0\x7e\0\0\0\x7b\x6a\xc8\
\xff\0\0\0\0\x61\x71\0\0\0\0\0\0\x7b\x1a\xd0\xff\0\0\0\0\xb7\x03\0\0\x04\0\0\0\
\xbf\x79\0\0\0\0\0\0\x0f\x39\0\0\0\0\0\0\x79\x71\x28\0\0\0\0\0\x79\x78\x30\0\0\
\0\0\0\x15\x08\x18\0\0\0\0\0\xb7\x02\0\0\0\0\0\0\x0f\x21\0\0\0\0\0\0\x61\x11\
\x04\0\0\0\0\0\x79\x83\x08\0\0\0\0\0\x67\x01\0\0\x03\0\0\0\x0f\x13\0\0\0\0\0\0\
\x79\x86\0\0\0\0\0\0\xbf\xa1\0\0\0\0\0\0\x07\x01\0\0\xf8\xff\xff\xff\xb7\x02\0\
\0\x08\0\0\0\x85\0\0\0\x71\0\0\0\xb7\x01\0\0\0\0\0\0\x79\xa3\xf8\xff\0\0\0\0\
\x0f\x13\0\0\0\0\0\0\xbf\xa1\0\0\0\0\0\0\x07\x01\0\0\xf4\xff\xff\xff\xb7\x02\0\
\0\x04\0\0\0\x85\0\0\0\x04\0\0\0\xb7\x03\0\0\x04\0\0\0\x61\xa1\xf4\xff\0\0\0\0\
\x61\x82\x10\0\0\0\0\0\x3d\x21\x02\0\0\0\0\0\x0f\x16\0\0\0\0\0\0\xbf\x69\0\0\0\
\0\0\0\x7b\x9a\xd8\xff\0\0\0\0\x79\x71\x18\0\0\0\0\0\x7b\x1a\xe0\xff\0\0\0\0\
\x79\x71\x20\0\0\0\0\0\x79\x11\0\0\0\0\0\0\x0f\x31\0\0\0\0\0\0\x7b\x1a\xe8\xff\
\0\0\0\0\xbf\xa4\0\0\0\0\0\0\x07\x04\0\0\xd0\xff\xff\xff\x79\xa1\xc8\xff\0\0\0\
\0\x18\x02\0\0\x51\0\0\0\0\0\0\0\0\0\0\0\xb7\x03\0\0\x11\0\0\0\xb7\x05\0\0\x20\
\0\0\0\x85\0\0\0\x7e\0\0\0\xb7\0\0\0\0\0\0\0\x95\0\0\0\0\0\0\0\x20\x20\x69\x64\
\x20\x6e\x61\x6d\x65\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x6d\
\x61\x78\x5f\x65\x6e\x74\x72\x69\x65\x73\x0a\0\x25\x34\x75\x20\x25\x2d\x31\x36\
\x73\x25\x36\x64\x0a\0\x20\x20\x69\x64\x20\x6e\x61\x6d\x65\x20\x20\x20\x20\x20\
\x20\x20\x20\x20\x20\x20\x20\x20\x61\x74\x74\x61\x63\x68\x65\x64\x0a\0\x25\x34\
\x75\x20\x25\x2d\x31\x36\x73\x20\x25\x73\x20\x25\x73\x0a\0\x47\x50\x4c\0\x9f\
\xeb\x01\0\x18\0\0\0\0\0\0\0\x1c\x04\0\0\x1c\x04\0\0\0\x05\0\0\0\0\0\0\0\0\0\
\x02\x02\0\0\0\x01\0\0\0\x02\0\0\x04\x10\0\0\0\x13\0\0\0\x03\0\0\0\0\0\0\0\x18\
\0\0\0\x04\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\x02\x08\0\0\0\0\0\0\0\0\0\0\x02\x0d\0\
\0\0\0\0\0\0\x01\0\0\x0d\x06\0\0\0\x1c\0\0\0\x01\0\0\0\x20\0\0\0\0\0\0\x01\x04\
\0\0\0\x20\0\0\x01\x24\0\0\0\x01\0\0\x0c\x05\0\0\0\xa3\0\0\0\x03\0\0\x04\x18\0\
\0\0\xb1\0\0\0\x09\0\0\0\0\0\0\0\xb5\0\0\0\x0b\0\0\0\x40\0\0\0\xc0\0\0\0\x0b\0\
\0\0\x80\0\0\0\0\0\0\0\0\0\0\x02\x0a\0\0\0\xc8\0\0\0\0\0\0\x07\0\0\0\0\xd1\0\0\
\0\0\0\0\x08\x0c\0\0\0\xd7\0\0\0\0\0\0\x01\x08\0\0\0\x40\0\0\0\x98\x01\0\0\x03\
\0\0\x04\x18\0\0\0\xa0\x01\0\0\x0e\0\0\0\0\0\0\0\xa3\x01\0\0\x11\0\0\0\x20\0\0\
\0\xa8\x01\0\0\x0e\0\0\0\xa0\0\0\0\xb4\x01\0\0\0\0\0\x08\x0f\0\0\0\xba\x01\0\0\
\0\0\0\x01\x04\0\0\0\x20\0\0\0\xc7\x01\0\0\0\0\0\x01\x01\0\0\0\x08\0\0\x01\0\0\
\0\0\0\0\0\x03\0\0\0\0\x10\0\0\0\x12\0\0\0\x10\0\0\0\xcc\x01\0\0\0\0\0\x01\x04\
\0\0\0\x20\0\0\0\0\0\0\0\0\0\0\x02\x14\0\0\0\x30\x02\0\0\x02\0\0\x04\x10\0\0\0\
\x13\0\0\0\x03\0\0\0\0\0\0\0\x43\x02\0\0\x15\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\x02\
\x18\0\0\0\0\0\0\0\x01\0\0\x0d\x06\0\0\0\x1c\0\0\0\x13\0\0\0\x48\x02\0\0\x01\0\
\0\x0c\x16\0\0\0\x94\x02\0\0\x01\0\0\x04\x08\0\0\0\x9d\x02\0\0\x19\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\x02\x1a\0\0\0\xee\x02\0\0\x06\0\0\x04\x38\0\0\0\xa0\x01\0\0\
\x0e\0\0\0\0\0\0\0\xa3\x01\0\0\x11\0\0\0\x20\0\0\0\xfb\x02\0\0\x1b\0\0\0\xc0\0\
\0\0\x0c\x03\0\0\x15\0\0\0\0\x01\0\0\x18\x03\0\0\x1d\0\0\0\x40\x01\0\0\x22\x03\
\0\0\x1e\0\0\0\x80\x01\0\0\0\0\0\0\0\0\0\x02\x1c\0\0\0\0\0\0\0\0\0\0\x0a\x10\0\
\0\0\0\0\0\0\0\0\0\x02\x1f\0\0\0\0\0\0\0\0\0\0\x02\x20\0\0\0\x6c\x03\0\0\x02\0\
\0\x04\x08\0\0\0\x7a\x03\0\0\x0e\0\0\0\0\0\0\0\x83\x03\0\0\x0e\0\0\0\x20\0\0\0\
\x22\x03\0\0\x03\0\0\x04\x18\0\0\0\x8d\x03\0\0\x1b\0\0\0\0\0\0\0\x95\x03\0\0\
\x21\0\0\0\x40\0\0\0\x9b\x03\0\0\x23\0\0\0\x80\0\0\0\0\0\0\0\0\0\0\x02\x22\0\0\
\0\0\0\0\0\0\0\0\x02\x24\0\0\0\x9f\x03\0\0\x01\0\0\x04\x04\0\0\0\xaa\x03\0\0\
\x0e\0\0\0\0\0\0\0\x13\x04\0\0\x01\0\0\x04\x04\0\0\0\x1c\x04\0\0\x0e\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\x03\0\0\0\0\x1c\0\0\0\x12\0\0\0\x23\0\0\0\x92\x04\0\0\0\0\0\
\x0e\x25\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\0\0\0\x1c\0\0\0\x12\0\0\0\x0e\0\0\0\
\xa6\x04\0\0\0\0\0\x0e\x27\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\0\0\0\x1c\0\0\0\
\x12\0\0\0\x20\0\0\0\xbc\x04\0\0\0\0\0\x0e\x29\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\
\0\0\0\0\x1c\0\0\0\x12\0\0\0\x11\0\0\0\xd1\x04\0\0\0\0\0\x0e\x2b\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\x03\0\0\0\0\x10\0\0\0\x12\0\0\0\x04\0\0\0\xe8\x04\0\0\0\0\0\x0e\
\x2d\0\0\0\x01\0\0\0\xf0\x04\0\0\x04\0\0\x0f\0\0\0\0\x26\0\0\0\0\0\0\0\x23\0\0\
\0\x28\0\0\0\x23\0\0\0\x0e\0\0\0\x2a\0\0\0\x31\0\0\0\x20\0\0\0\x2c\0\0\0\x51\0\
\0\0\x11\0\0\0\xf8\x04\0\0\x01\0\0\x0f\0\0\0\0\x2e\0\0\0\0\0\0\0\x04\0\0\0\0\
\x62\x70\x66\x5f\x69\x74\x65\x72\x5f\x5f\x62\x70\x66\x5f\x6d\x61\x70\0\x6d\x65\
\x74\x61\0\x6d\x61\x70\0\x63\x74\x78\0\x69\x6e\x74\0\x64\x75\x6d\x70\x5f\x62\
\x70\x66\x5f\x6d\x61\x70\0\x69\x74\x65\x72\x2f\x62\x70\x66\x5f\x6d\x61\x70\0\
\x30\x3a\x30\0\x2f\x77\x2f\x6e\x65\x74\x2d\x6e\x65\x78\x74\x2f\x6b\x65\x72\x6e\
\x65\x6c\x2f\x62\x70\x66\x2f\x70\x72\x65\x6c\x6f\x61\x64\x2f\x69\x74\x65\x72\
\x61\x74\x6f\x72\x73\x2f\x69\x74\x65\x72\x61\x74\x6f\x72\x73\x2e\x62\x70\x66\
\x2e\x63\0\x09\x73\x74\x72\x75\x63\x74\x20\x73\x65\x71\x5f\x66\x69\x6c\x65\x20\
\x2a\x73\x65\x71\x20\x3d\x20\x63\x74\x78\x2d\x3e\x6d\x65\x74\x61\x2d\x3e\x73\
\x65\x71\x3b\0\x62\x70\x66\x5f\x69\x74\x65\x72\x5f\x6d\x65\x74\x61\0\x73\x65\
\x71\0\x73\x65\x73\x73\x69\x6f\x6e\x5f\x69\x64\0\x73\x65\x71\x5f\x6e\x75\x6d\0\
\x73\x65\x71\x5f\x66\x69\x6c\x65\0\x5f\x5f\x75\x36\x34\0\x6c\x6f\x6e\x67\x20\
\x6c\x6f\x6e\x67\x20\x75\x6e\x73\x69\x67\x6e\x65\x64\x20\x69\x6e\x74\0\x30\x3a\
\x31\0\x09\x73\x74\x72\x75\x63\x74\x20\x62\x70\x66\x5f\x6d\x61\x70\x20\x2a\x6d\
\x61\x70\x20\x3d\x20\x63\x74\x78\x2d\x3e\x6d\x61\x70\x3b\0\x09\x69\x66\x20\x28\
\x21\x6d\x61\x70\x29\0\x30\x3a\x32\0\x09\x5f\x5f\x75\x36\x34\x20\x73\x65\x71\
\x5f\x6e\x75\x6d\x20\x3d\x20\x63\x74\x78\x2d\x3e\x6d\x65\x74\x61\x2d\x3e\x73\
\x65\x71\x5f\x6e\x75\x6d\x3b\0\x09\x69\x66\x20\x28\x73\x65\x71\x5f\x6e\x75\x6d\
\x20\x3d\x3d\x20\x30\x29\0\x09\x09\x42\x50\x46\x5f\x53\x45\x51\x5f\x50\x52\x49\
\x4e\x54\x46\x28\x73\x65\x71\x2c\x20\x22\x20\x20\x69\x64\x20\x6e\x61\x6d\x65\
\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x6d\x61\x78\x5f\x65\x6e\
\x74\x72\x69\x65\x73\x5c\x6e\x22\x29\x3b\0\x62\x70\x66\x5f\x6d\x61\x70\0\x69\
\x64\0\x6e\x61\x6d\x65\0\x6d\x61\x78\x5f\x65\x6e\x74\x72\x69\x65\x73\0\x5f\x5f\
\x75\x33\x32\0\x75\x6e\x73\x69\x67\x6e\x65\x64\x20\x69\x6e\x74\0\x63\x68\x61\
\x72\0\x5f\x5f\x41\x52\x52\x41\x59\x5f\x53\x49\x5a\x45\x5f\x54\x59\x50\x45\x5f\
\x5f\0\x09\x42\x50\x46\x5f\x53\x45\x51\x5f\x50\x52\x49\x4e\x54\x46\x28\x73\x65\
\x71\x2c\x20\x22\x25\x34\x75\x20\x25\x2d\x31\x36\x73\x25\x36\x64\x5c\x6e\x22\
\x2c\x20\x6d\x61\x70\x2d\x3e\x69\x64\x2c\x20\x6d\x61\x70\x2d\x3e\x6e\x61\x6d\
\x65\x2c\x20\x6d\x61\x70\x2d\x3e\x6d\x61\x78\x5f\x65\x6e\x74\x72\x69\x65\x73\
\x29\x3b\0\x7d\0\x62\x70\x66\x5f\x69\x74\x65\x72\x5f\x5f\x62\x70\x66\x5f\x70\
\x72\x6f\x67\0\x70\x72\x6f\x67\0\x64\x75\x6d\x70\x5f\x62\x70\x66\x5f\x70\x72\
\x6f\x67\0\x69\x74\x65\x72\x2f\x62\x70\x66\x5f\x70\x72\x6f\x67\0\x09\x73\x74\
\x72\x75\x63\x74\x20\x62\x70\x66\x5f\x70\x72\x6f\x67\x20\x2a\x70\x72\x6f\x67\
\x20\x3d\x20\x63\x74\x78\x2d\x3e\x70\x72\x6f\x67\x3b\0\x09\x69\x66\x20\x28\x21\
\x70\x72\x6f\x67\x29\0\x62\x70\x66\x5f\x70\x72\x6f\x67\0\x61\x75\x78\0\x09\x61\
\x75\x78\x20\x3d\x20\x70\x72\x6f\x67\x2d\x3e\x61\x75\x78\x3b\0\x09\x09\x42\x50\
\x46\x5f\x53\x45\x51\x5f\x50\x52\x49\x4e\x54\x46\x28\x73\x65\x71\x2c\x20\x22\
\x20\x20\x69\x64\x20\x6e\x61\x6d\x65\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\
\x20\x20\x20\x61\x74\x74\x61\x63\x68\x65\x64\x5c\x6e\x22\x29\x3b\0\x62\x70\x66\
\x5f\x70\x72\x6f\x67\x5f\x61\x75\x78\0\x61\x74\x74\x61\x63\x68\x5f\x66\x75\x6e\
\x63\x5f\x6e\x61\x6d\x65\0\x6c\x69\x6e\x6b\x65\x64\x5f\x70\x72\x6f\x67\0\x66\
\x75\x6e\x63\x5f\x69\x6e\x66\x6f\0\x62\x74\x66\0\x09\x42\x50\x46\x5f\x53\x45\
\x51\x5f\x50\x52\x49\x4e\x54\x46\x28\x73\x65\x71\x2c\x20\x22\x25\x34\x75\x20\
\x25\x2d\x31\x36\x73\x20\x25\x73\x20\x25\x73\x5c\x6e\x22\x2c\x20\x61\x75\x78\
\x2d\x3e\x69\x64\x2c\0\x30\x3a\x34\0\x30\x3a\x35\0\x09\x69\x66\x20\x28\x21\x62\
\x74\x66\x29\0\x62\x70\x66\x5f\x66\x75\x6e\x63\x5f\x69\x6e\x66\x6f\0\x69\x6e\
\x73\x6e\x5f\x6f\x66\x66\0\x74\x79\x70\x65\x5f\x69\x64\0\x30\0\x73\x74\x72\x69\
\x6e\x67\x73\0\x74\x79\x70\x65\x73\0\x68\x64\x72\0\x62\x74\x66\x5f\x68\x65\x61\
\x64\x65\x72\0\x73\x74\x72\x5f\x6c\x65\x6e\0\x09\x74\x79\x70\x65\x73\x20\x3d\
\x20\x62\x74\x66\x2d\x3e\x74\x79\x70\x65\x73\x3b\0\x09\x62\x70\x66\x5f\x70\x72\
\x6f\x62\x65\x5f\x72\x65\x61\x64\x5f\x6b\x65\x72\x6e\x65\x6c\x28\x26\x74\x2c\
\x20\x73\x69\x7a\x65\x6f\x66\x28\x74\x29\x2c\x20\x74\x79\x70\x65\x73\x20\x2b\
\x20\x62\x74\x66\x5f\x69\x64\x29\x3b\0\x09\x73\x74\x72\x20\x3d\x20\x62\x74\x66\
\x2d\x3e\x73\x74\x72\x69\x6e\x67\x73\x3b\0\x62\x74\x66\x5f\x74\x79\x70\x65\0\
\x6e\x61\x6d\x65\x5f\x6f\x66\x66\0\x09\x6e\x61\x6d\x65\x5f\x6f\x66\x66\x20\x3d\
\x20\x42\x50\x46\x5f\x43\x4f\x52\x45\x5f\x52\x45\x41\x44\x28\x74\x2c\x20\x6e\
\x61\x6d\x65\x5f\x6f\x66\x66\x29\x3b\0\x30\x3a\x32\x3a\x30\0\x09\x69\x66\x20\
\x28\x6e\x61\x6d\x65\x5f\x6f\x66\x66\x20\x3e\x3d\x20\x62\x74\x66\x2d\x3e\x68\
\x64\x72\x2e\x73\x74\x72\x5f\x6c\x65\x6e\x29\0\x09\x72\x65\x74\x75\x72\x6e\x20\
\x73\x74\x72\x20\x2b\x20\x6e\x61\x6d\x65\x5f\x6f\x66\x66\x3b\0\x30\x3a\x33\0\
\x64\x75\x6d\x70\x5f\x62\x70\x66\x5f\x6d\x61\x70\x2e\x5f\x5f\x5f\x66\x6d\x74\0\
\x64\x75\x6d\x70\x5f\x62\x70\x66\x5f\x6d\x61\x70\x2e\x5f\x5f\x5f\x66\x6d\x74\
\x2e\x31\0\x64\x75\x6d\x70\x5f\x62\x70\x66\x5f\x70\x72\x6f\x67\x2e\x5f\x5f\x5f\
\x66\x6d\x74\0\x64\x75\x6d\x70\x5f\x62\x70\x66\x5f\x70\x72\x6f\x67\x2e\x5f\x5f\
\x5f\x66\x6d\x74\x2e\x32\0\x4c\x49\x43\x45\x4e\x53\x45\0\x2e\x72\x6f\x64\x61\
\x74\x61\0\x6c\x69\x63\x65\x6e\x73\x65\0\x9f\xeb\x01\0\x20\0\0\0\0\0\0\0\x24\0\
\0\0\x24\0\0\0\x44\x02\0\0\x68\x02\0\0\xa4\x01\0\0\x08\0\0\0\x31\0\0\0\x01\0\0\
\0\0\0\0\0\x07\0\0\0\x56\x02\0\0\x01\0\0\0\0\0\0\0\x17\0\0\0\x10\0\0\0\x31\0\0\
\0\x09\0\0\0\0\0\0\0\x42\0\0\0\x7b\0\0\0\x1e\x40\x01\0\x08\0\0\0\x42\0\0\0\x7b\
\0\0\0\x24\x40\x01\0\x10\0\0\0\x42\0\0\0\xf2\0\0\0\x1d\x48\x01\0\x18\0\0\0\x42\
\0\0\0\x13\x01\0\0\x06\x50\x01\0\x20\0\0\0\x42\0\0\0\x22\x01\0\0\x1d\x44\x01\0\
\x28\0\0\0\x42\0\0\0\x47\x01\0\0\x06\x5c\x01\0\x38\0\0\0\x42\0\0\0\x5a\x01\0\0\
\x03\x60\x01\0\x70\0\0\0\x42\0\0\0\xe0\x01\0\0\x02\x68\x01\0\xf0\0\0\0\x42\0\0\
\0\x2e\x02\0\0\x01\x70\x01\0\x56\x02\0\0\x1a\0\0\0\0\0\0\0\x42\0\0\0\x7b\0\0\0\
\x1e\x84\x01\0\x08\0\0\0\x42\0\0\0\x7b\0\0\0\x24\x84\x01\0\x10\0\0\0\x42\0\0\0\
\x64\x02\0\0\x1f\x8c\x01\0\x18\0\0\0\x42\0\0\0\x88\x02\0\0\x06\x98\x01\0\x20\0\
\0\0\x42\0\0\0\xa1\x02\0\0\x0e\xa4\x01\0\x28\0\0\0\x42\0\0\0\x22\x01\0\0\x1d\
\x88\x01\0\x30\0\0\0\x42\0\0\0\x47\x01\0\0\x06\xa8\x01\0\x40\0\0\0\x42\0\0\0\
\xb3\x02\0\0\x03\xac\x01\0\x80\0\0\0\x42\0\0\0\x26\x03\0\0\x02\xb4\x01\0\xb8\0\
\0\0\x42\0\0\0\x61\x03\0\0\x06\x08\x01\0\xd0\0\0\0\x42\0\0\0\0\0\0\0\0\0\0\0\
\xd8\0\0\0\x42\0\0\0\xb2\x03\0\0\x0f\x14\x01\0\xe0\0\0\0\x42\0\0\0\xc7\x03\0\0\
\x2d\x18\x01\0\xf0\0\0\0\x42\0\0\0\xfe\x03\0\0\x0d\x10\x01\0\0\x01\0\0\x42\0\0\
\0\0\0\0\0\0\0\0\0\x08\x01\0\0\x42\0\0\0\xc7\x03\0\0\x02\x18\x01\0\x20\x01\0\0\
\x42\0\0\0\x25\x04\0\0\x0d\x1c\x01\0\x38\x01\0\0\x42\0\0\0\0\0\0\0\0\0\0\0\x40\
\x01\0\0\x42\0\0\0\x25\x04\0\0\x0d\x1c\x01\0\x58\x01\0\0\x42\0\0\0\x25\x04\0\0\
\x0d\x1c\x01\0\x60\x01\0\0\x42\0\0\0\x53\x04\0\0\x1b\x20\x01\0\x68\x01\0\0\x42\
\0\0\0\x53\x04\0\0\x06\x20\x01\0\x70\x01\0\0\x42\0\0\0\x76\x04\0\0\x0d\x28\x01\
\0\x78\x01\0\0\x42\0\0\0\0\0\0\0\0\0\0\0\x80\x01\0\0\x42\0\0\0\x26\x03\0\0\x02\
\xb4\x01\0\xf8\x01\0\0\x42\0\0\0\x2e\x02\0\0\x01\xc4\x01\0\x10\0\0\0\x31\0\0\0\
\x07\0\0\0\0\0\0\0\x02\0\0\0\x3e\0\0\0\0\0\0\0\x08\0\0\0\x08\0\0\0\x3e\0\0\0\0\
\0\0\0\x10\0\0\0\x02\0\0\0\xee\0\0\0\0\0\0\0\x20\0\0\0\x08\0\0\0\x1e\x01\0\0\0\
\0\0\0\x70\0\0\0\x0d\0\0\0\x3e\0\0\0\0\0\0\0\x80\0\0\0\x0d\0\0\0\xee\0\0\0\0\0\
\0\0\xa0\0\0\0\x0d\0\0\0\x1e\x01\0\0\0\0\0\0\x56\x02\0\0\x12\0\0\0\0\0\0\0\x14\
\0\0\0\x3e\0\0\0\0\0\0\0\x08\0\0\0\x08\0\0\0\x3e\0\0\0\0\0\0\0\x10\0\0\0\x14\0\
\0\0\xee\0\0\0\0\0\0\0\x20\0\0\0\x18\0\0\0\x3e\0\0\0\0\0\0\0\x28\0\0\0\x08\0\0\
\0\x1e\x01\0\0\0\0\0\0\x80\0\0\0\x1a\0\0\0\x3e\0\0\0\0\0\0\0\x90\0\0\0\x1a\0\0\
\0\xee\0\0\0\0\0\0\0\xa8\0\0\0\x1a\0\0\0\x59\x03\0\0\0\0\0\0\xb0\0\0\0\x1a\0\0\
\0\x5d\x03\0\0\0\0\0\0\xc0\0\0\0\x1f\0\0\0\x8b\x03\0\0\0\0\0\0\xd8\0\0\0\x20\0\
\0\0\xee\0\0\0\0\0\0\0\xf0\0\0\0\x20\0\0\0\x3e\0\0\0\0\0\0\0\x18\x01\0\0\x24\0\
\0\0\x3e\0\0\0\0\0\0\0\x50\x01\0\0\x1a\0\0\0\xee\0\0\0\0\0\0\0\x60\x01\0\0\x20\
\0\0\0\x4d\x04\0\0\0\0\0\0\x88\x01\0\0\x1a\0\0\0\x1e\x01\0\0\0\0\0\0\x98\x01\0\
\0\x1a\0\0\0\x8e\x04\0\0\0\0\0\0\xa0\x01\0\0\x18\0\0\0\x3e\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xd6\0\0\0\0\0\x02\0\x70\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\xc8\0\0\0\0\0\x02\0\xf0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\xcf\0\0\0\0\0\x03\0\x78\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xc1\0\0\0\0\0\x03\0\x80\
\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xba\0\0\0\0\0\x03\0\xf8\x01\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x14\0\0\0\x01\0\x04\0\0\0\0\0\0\0\0\0\x23\0\0\0\0\0\0\0\xf4\0\0\0\
\x01\0\x04\0\x23\0\0\0\0\0\0\0\x0e\0\0\0\0\0\0\0\x28\0\0\0\x01\0\x04\0\x31\0\0\
\0\0\0\0\0\x20\0\0\0\0\0\0\0\xdd\0\0\0\x01\0\x04\0\x51\0\0\0\0\0\0\0\x11\0\0\0\
\0\0\0\0\0\0\0\0\x03\0\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\x03\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\xb2\0\0\0\x11\0\x05\0\0\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\x3d\0\0\0\x12\
\0\x02\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\x5b\0\0\0\x12\0\x03\0\0\0\0\0\0\0\0\
\0\x08\x02\0\0\0\0\0\0\x48\0\0\0\0\0\0\0\x01\0\0\0\x0c\0\0\0\xc8\0\0\0\0\0\0\0\
\x01\0\0\0\x0c\0\0\0\x50\0\0\0\0\0\0\0\x01\0\0\0\x0c\0\0\0\xd0\x01\0\0\0\0\0\0\
\x01\0\0\0\x0c\0\0\0\xf0\x03\0\0\0\0\0\0\x0a\0\0\0\x0c\0\0\0\xfc\x03\0\0\0\0\0\
\0\x0a\0\0\0\x0c\0\0\0\x08\x04\0\0\0\0\0\0\x0a\0\0\0\x0c\0\0\0\x14\x04\0\0\0\0\
\0\0\x0a\0\0\0\x0c\0\0\0\x2c\x04\0\0\0\0\0\0\0\0\0\0\x0d\0\0\0\x2c\0\0\0\0\0\0\
\0\0\0\0\0\x0a\0\0\0\x3c\0\0\0\0\0\0\0\0\0\0\0\x0b\0\0\0\x50\0\0\0\0\0\0\0\0\0\
\0\0\x0a\0\0\0\x60\0\0\0\0\0\0\0\0\0\0\0\x0a\0\0\0\x70\0\0\0\0\0\0\0\0\0\0\0\
\x0a\0\0\0\x80\0\0\0\0\0\0\0\0\0\0\0\x0a\0\0\0\x90\0\0\0\0\0\0\0\0\0\0\0\x0a\0\
\0\0\xa0\0\0\0\0\0\0\0\0\0\0\0\x0a\0\0\0\xb0\0\0\0\0\0\0\0\0\0\0\0\x0a\0\0\0\
\xc0\0\0\0\0\0\0\0\0\0\0\0\x0a\0\0\0\xd0\0\0\0\0\0\0\0\0\0\0\0\x0a\0\0\0\xe8\0\
\0\0\0\0\0\0\0\0\0\0\x0b\0\0\0\xf8\0\0\0\0\0\0\0\0\0\0\0\x0b\0\0\0\x08\x01\0\0\
\0\0\0\0\0\0\0\0\x0b\0\0\0\x18\x01\0\0\0\0\0\0\0\0\0\0\x0b\0\0\0\x28\x01\0\0\0\
\0\0\0\0\0\0\0\x0b\0\0\0\x38\x01\0\0\0\0\0\0\0\0\0\0\x0b\0\0\0\x48\x01\0\0\0\0\
\0\0\0\0\0\0\x0b\0\0\0\x58\x01\0\0\0\0\0\0\0\0\0\0\x0b\0\0\0\x68\x01\0\0\0\0\0\
\0\0\0\0\0\x0b\0\0\0\x78\x01\0\0\0\0\0\0\0\0\0\0\x0b\0\0\0\x88\x01\0\0\0\0\0\0\
\0\0\0\0\x0b\0\0\0\x98\x01\0\0\0\0\0\0\0\0\0\0\x0b\0\0\0\xa8\x01\0\0\0\0\0\0\0\
\0\0\0\x0b\0\0\0\xb8\x01\0\0\0\0\0\0\0\0\0\0\x0b\0\0\0\xc8\x01\0\0\0\0\0\0\0\0\
\0\0\x0b\0\0\0\xd8\x01\0\0\0\0\0\0\0\0\0\0\x0b\0\0\0\xe8\x01\0\0\0\0\0\0\0\0\0\
\0\x0b\0\0\0\xf8\x01\0\0\0\0\0\0\0\0\0\0\x0b\0\0\0\x08\x02\0\0\0\0\0\0\0\0\0\0\
\x0b\0\0\0\x18\x02\0\0\0\0\0\0\0\0\0\0\x0b\0\0\0\x28\x02\0\0\0\0\0\0\0\0\0\0\
\x0b\0\0\0\x38\x02\0\0\0\0\0\0\0\0\0\0\x0b\0\0\0\x48\x02\0\0\0\0\0\0\0\0\0\0\
\x0b\0\0\0\x58\x02\0\0\0\0\0\0\0\0\0\0\x0b\0\0\0\x68\x02\0\0\0\0\0\0\0\0\0\0\
\x0b\0\0\0\x78\x02\0\0\0\0\0\0\0\0\0\0\x0b\0\0\0\x94\x02\0\0\0\0\0\0\0\0\0\0\
\x0a\0\0\0\xa4\x02\0\0\0\0\0\0\0\0\0\0\x0a\0\0\0\xb4\x02\0\0\0\0\0\0\0\0\0\0\
\x0a\0\0\0\xc4\x02\0\0\0\0\0\0\0\0\0\0\x0a\0\0\0\xd4\x02\0\0\0\0\0\0\0\0\0\0\
\x0a\0\0\0\xe4\x02\0\0\0\0\0\0\0\0\0\0\x0a\0\0\0\xf4\x02\0\0\0\0\0\0\0\0\0\0\
\x0a\0\0\0\x0c\x03\0\0\0\0\0\0\0\0\0\0\x0b\0\0\0\x1c\x03\0\0\0\0\0\0\0\0\0\0\
\x0b\0\0\0\x2c\x03\0\0\0\0\0\0\0\0\0\0\x0b\0\0\0\x3c\x03\0\0\0\0\0\0\0\0\0\0\
\x0b\0\0\0\x4c\x03\0\0\0\0\0\0\0\0\0\0\x0b\0\0\0\x5c\x03\0\0\0\0\0\0\0\0\0\0\
\x0b\0\0\0\x6c\x03\0\0\0\0\0\0\0\0\0\0\x0b\0\0\0\x7c\x03\0\0\0\0\0\0\0\0\0\0\
\x0b\0\0\0\x8c\x03\0\0\0\0\0\0\0\0\0\0\x0b\0\0\0\x9c\x03\0\0\0\0\0\0\0\0\0\0\
\x0b\0\0\0\xac\x03\0\0\0\0\0\0\0\0\0\0\x0b\0\0\0\xbc\x03\0\0\0\0\0\0\0\0\0\0\
\x0b\0\0\0\xcc\x03\0\0\0\0\0\0\0\0\0\0\x0b\0\0\0\xdc\x03\0\0\0\0\0\0\0\0\0\0\
\x0b\0\0\0\xec\x03\0\0\0\0\0\0\0\0\0\0\x0b\0\0\0\xfc\x03\0\0\0\0\0\0\0\0\0\0\
\x0b\0\0\0\x0c\x04\0\0\0\0\0\0\0\0\0\0\x0b\0\0\0\x1c\x04\0\0\0\0\0\0\0\0\0\0\
\x0b\0\0\0\x4e\x4f\x41\x42\x43\x44\x4d\0\x2e\x74\x65\x78\x74\0\x2e\x72\x65\x6c\
\x2e\x42\x54\x46\x2e\x65\x78\x74\0\x64\x75\x6d\x70\x5f\x62\x70\x66\x5f\x6d\x61\
\x70\x2e\x5f\x5f\x5f\x66\x6d\x74\0\x64\x75\x6d\x70\x5f\x62\x70\x66\x5f\x70\x72\
\x6f\x67\x2e\x5f\x5f\x5f\x66\x6d\x74\0\x64\x75\x6d\x70\x5f\x62\x70\x66\x5f\x6d\
\x61\x70\0\x2e\x72\x65\x6c\x69\x74\x65\x72\x2f\x62\x70\x66\x5f\x6d\x61\x70\0\
\x64\x75\x6d\x70\x5f\x62\x70\x66\x5f\x70\x72\x6f\x67\0\x2e\x72\x65\x6c\x69\x74\
\x65\x72\x2f\x62\x70\x66\x5f\x70\x72\x6f\x67\0\x2e\x6c\x6c\x76\x6d\x5f\x61\x64\
\x64\x72\x73\x69\x67\0\x6c\x69\x63\x65\x6e\x73\x65\0\x2e\x73\x74\x72\x74\x61\
\x62\0\x2e\x73\x79\x6d\x74\x61\x62\0\x2e\x72\x6f\x64\x61\x74\x61\0\x2e\x72\x65\
\x6c\x2e\x42\x54\x46\0\x4c\x49\x43\x45\x4e\x53\x45\0\x4c\x42\x42\x31\x5f\x37\0\
\x4c\x42\x42\x31\x5f\x36\0\x4c\x42\x42\x30\x5f\x34\0\x4c\x42\x42\x31\x5f\x33\0\
\x4c\x42\x42\x30\x5f\x33\0\x64\x75\x6d\x70\x5f\x62\x70\x66\x5f\x70\x72\x6f\x67\
\x2e\x5f\x5f\x5f\x66\x6d\x74\x2e\x32\0\x64\x75\x6d\x70\x5f\x62\x70\x66\x5f\x6d\
\x61\x70\x2e\x5f\x5f\x5f\x66\x6d\x74\x2e\x31\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\x4e\0\0\0\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\
\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x6d\0\0\0\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x40\x01\0\0\0\0\0\0\x08\
\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xa1\0\0\0\
\x01\0\0\0\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x48\x03\0\0\0\0\0\0\x62\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x89\0\0\0\x01\0\0\0\x03\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xaa\x03\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xad\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\xae\x03\0\0\0\0\0\0\x34\x09\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\x0b\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\xe2\x0c\0\0\0\0\0\0\x2c\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\x99\0\0\0\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x10\x11\0\0\0\
\0\0\0\x80\x01\0\0\0\0\0\0\x0e\0\0\0\x0d\0\0\0\x08\0\0\0\0\0\0\0\x18\0\0\0\0\0\
\0\0\x4a\0\0\0\x09\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x90\x12\0\0\0\0\0\0\
\x20\0\0\0\0\0\0\0\x08\0\0\0\x02\0\0\0\x08\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\x69\
\0\0\0\x09\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xb0\x12\0\0\0\0\0\0\x20\0\0\0\
\0\0\0\0\x08\0\0\0\x03\0\0\0\x08\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\xa9\0\0\0\x09\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xd0\x12\0\0\0\0\0\0\x50\0\0\0\0\0\0\0\
\x08\0\0\0\x06\0\0\0\x08\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\x07\0\0\0\x09\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x20\x13\0\0\0\0\0\0\xe0\x03\0\0\0\0\0\0\x08\0\0\
\0\x07\0\0\0\x08\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\x7b\0\0\0\x03\x4c\xff\x6f\0\0\
\0\x80\0\0\0\0\0\0\0\0\0\0\0\0\0\x17\0\0\0\0\0\0\x07\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x91\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\x07\x17\0\0\0\0\0\0\x0a\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0";

	return 0;
err:
	bpf_object__destroy_skeleton(s);
	return -1;
}

#endif /* __ITERATORS_BPF_SKEL_H__ */
