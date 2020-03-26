//For shared_ptr memeory leaks 

//f(std::shared_ptr<int>(new int(42)), g()) can cause a memory leak if g throws an exception because g() may be called after new int(42) and before the constructor of shared_ptr<int>. 
//This doesn't occur in f(std::make_shared<int>(42), g()), since two function calls are never interleaved.

//This also works 
//auto memory_related_arg = std::shared_ptr<MyThing>(new MyThing());
//processThing(memory_related_arg, get_num_samples());



