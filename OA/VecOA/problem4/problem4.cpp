#include<unistd.h>
#include<utility> 

class FileDescriptor{
public: 
	explicit FileDescriptor(int fd) : fd_(fd) {}

	~FileDescriptor() {
		if (fd_ != -1) {
			close(fd_); 
		}
	}
	
	int operator*() const {
		return fd_;
	}
private: 
	int fd_ = -1;
};

/*
What are the minimal changes that would be required to make the class: 
1. hard to accidentally misuse (e.g. causing an invalid or undesired file descriptor to be closed), and 
2. usable as a return value from a function? 
*/


