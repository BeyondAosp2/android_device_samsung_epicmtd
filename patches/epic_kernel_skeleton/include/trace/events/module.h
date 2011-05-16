#undef TRACE_SYSTEM
#define TRACE_SYSTEM module

#if !defined(_TRACE_MODULE_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_MODULE_H

#include <linux/tracepoint.h>


struct module;

#define show_module_flags(flags) __print_flags(flags, "",	\
	{ (1UL << TAINT_PROPRIETARY_MODULE),	"P" },		\
	{ (1UL << TAINT_FORCED_MODULE),		"F" },		\
	{ (1UL << TAINT_CRAP),			"C" })

TRACE_EVENT(module_load,

	TP_PROTO(struct module *mod),

	TP_ARGS(mod),

	TP_STRUCT__entry(
		__field(	unsigned int,	taints		)
		__string(	name,		mod->name	)
	),

	TP_fast_assign(
		__entry->taints = mod->taints;
		__assign_str(name, mod->name);
	),

	TP_printk("%s %s", __get_str(name), show_module_flags(__entry->taints))
);

TRACE_EVENT(module_free,

	TP_PROTO(struct module *mod),

	TP_ARGS(mod),

	TP_STRUCT__entry(
		__string(	name,		mod->name	)
	),

	TP_fast_assign(
		__assign_str(name, mod->name);
	),

	TP_printk("%s", __get_str(name))
);

TRACE_EVENT(module_get,

	TP_PROTO(struct module *mod, unsigned long ip, int refcnt),

	TP_ARGS(mod, ip, refcnt),

	TP_STRUCT__entry(
		__field(	unsigned long,	ip		)
		__field(	int,		refcnt		)
		__string(	name,		mod->name	)
	),

	TP_fast_assign(
		__entry->ip	= ip;
		__entry->refcnt	= refcnt;
		__assign_str(name, mod->name);
	),

	TP_printk("%s call_site=%pf refcnt=%d",
		  __get_str(name), (void *)__entry->ip, __entry->refcnt)
);

TRACE_EVENT(module_put,

	TP_PROTO(struct module *mod, unsigned long ip, int refcnt),

	TP_ARGS(mod, ip, refcnt),

	TP_STRUCT__entry(
		__field(	unsigned long,	ip		)
		__field(	int,		refcnt		)
		__string(	name,		mod->name	)
	),

	TP_fast_assign(
		__entry->ip	= ip;
		__entry->refcnt	= refcnt;
		__assign_str(name, mod->name);
	),

	TP_printk("%s call_site=%pf refcnt=%d",
		  __get_str(name), (void *)__entry->ip, __entry->refcnt)
);

TRACE_EVENT(module_request,

	TP_PROTO(char *name, bool wait, unsigned long ip),

	TP_ARGS(name, wait, ip),

	TP_STRUCT__entry(
		__field(	bool,		wait		)
		__field(	unsigned long,	ip		)
		__string(	name,		name		)
	),

	TP_fast_assign(
		__entry->wait	= wait;
		__entry->ip	= ip;
		__assign_str(name, name);
	),

	TP_printk("%s wait=%d call_site=%pf",
		  __get_str(name), (int)__entry->wait, (void *)__entry->ip)
);


#endif /* _TRACE_MODULE_H */

/* This part must be outside protection */
#include <trace/define_trace.h>

