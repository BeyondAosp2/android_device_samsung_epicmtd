#ifndef __NET_WEXT_H
#define __NET_WEXT_H

/*
 * wireless extensions interface to the core code
 */

struct net;

extern int wext_proc_init(struct net *net);
extern void wext_proc_exit(struct net *net);
extern int wext_handle_ioctl(struct net *net, struct ifreq *ifr, unsigned int cmd,
			     void __user *arg);
extern int compat_wext_handle_ioctl(struct net *net, unsigned int cmd,
				    unsigned long arg);
extern struct iw_statistics *get_wireless_stats(struct net_device *dev);

#endif /* __NET_WEXT_H */
