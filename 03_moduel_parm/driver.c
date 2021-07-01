#include<linux/init.h>
#include<linux/module.h>

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("MYFIRST MODULE");
MODULE_AUTHOR("SHARATH");
int number;
module_param(number,int,S_IRUGO);

static int __init init_fxn(void ) 
{
	printk(KERN_INFO "NUMBER:%d",number);
	printk(KERN_INFO "testing module_param\n");
	return 0;
}

static void __exit exit_fxn(void )
{
	printk(KERN_INFO "exit from module_peram\n");

}

module_init(init_fxn);
module_exit(exit_fxn);


