#include<linux/init.h>
#include<linux/module.h>
#include<linux/fs.h>
#include<linux/cdev.h>

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("New Driver Registration");
MODULE_AUTHOR("SHARATH");


dev_t major_num =0;
int minor_num=0;
char driver_name[50] = "Simple_driver";
int ret;


ssize_t readdev (struct file * filep, char __user * used_d , size_t size , loff_t * l_loff)
{ 
	printk(KERN_INFO "Readdev called");
	return 0;
}

ssize_t writedev (struct file * filep, const char __user * used_d , size_t size , loff_t * l_loff)
{
	printk(KERN_INFO "Writedev called");
	return 0;

}
int opendev (struct inode * inode_d, struct file * filep)
{
	 printk(KERN_INFO "opendev called");
	 return 0;
}

int closedev (struct inode * inode_d, struct file * filep)
{
	 printk(KERN_INFO "closedev called");
	 return 0;

}


struct file_operations fops ={
	read	:  readdev,
	write  :  writedev,
	open   :  opendev,
	release :  closedev

};

struct cdev c_dev;
static int __init init_fxn(void ) 
{
	//extern int alloc_chrdev_region(dev_t *, unsigned, unsigned, const char *); {Dynamically register }
	//extern int register_chrdev_region(dev_t, unsigned, const char *); {static}
	
	ret=alloc_chrdev_region(&major_num,minor_num,1,driver_name);
	//Driver is registed dynamically 

	if(ret==-1)
	{
		printk(KERN_INFO "Failed to register driver\n");
	}
	printk(KERN_INFO "Major_num:%d minor_num:%d\n",MAJOR(major_num),MINOR(major_num));

	cdev_init( &c_dev, &fops);  //initialization of char driver 
	cdev_add( &c_dev,major_num,1);  // add the information 
	
	printk(KERN_INFO "Driver was Successfully registered\n");
	return 0;
}

static void __exit exit_fxn(void )
{
	//extern void unregister_chrdev_region(dev_t, unsigned); {remove the driver}
	unregister_chrdev_region(major_num, 1);

	printk(KERN_INFO "Driver removed successfullly\n");
       //Diver is removed from kernel  
       //if it is not removed. Try to restart the kernel 
	

}

module_init(init_fxn);
module_exit(exit_fxn);


