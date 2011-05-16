#ifndef _LINUX_RAMFS_H
#define _LINUX_RAMFS_H

struct inode *ramfs_get_inode(struct super_block *sb, int mode, dev_t dev);
extern int ramfs_get_sb(struct file_system_type *fs_type,
	 int flags, const char *dev_name, void *data, struct vfsmount *mnt);


extern const struct file_operations ramfs_file_operations;
extern const struct vm_operations_struct generic_file_vm_ops;
extern int __init init_rootfs(void);

#endif
