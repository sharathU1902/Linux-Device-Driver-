#include<linux/init.h>
#include<linux/module.h>

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("MYFIRST MODULE");
MODULE_AUTHOR("SHARATH");

void basic_fun(void);

static int __init init_fxn(void ) 
{
	basic_fun();
	printk(KERN_INFO "It is used export symbol\n");
	return 0;
}

static void __exit exit_fxn(void )
{
	printk(KERN_INFO "exit from 01_export_symbol\n");

}

module_init(init_fxn);
module_exit(exit_fxn);


