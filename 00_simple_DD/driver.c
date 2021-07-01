#include<linux/init.h>
#include<linux/module.h>

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("MYFIRST MODULE");
MODULE_AUTHOR("SHARATH");

static int __init init_fxn(void ) 
{
	printk(KERN_INFO "Hello kernal\n");
	return 0;
}
static void __exit exit_fxn(void )
{
	printk(KERN_INFO "exit from kernal\n");

}

module_init(init_fxn);
module_exit(exit_fxn);
