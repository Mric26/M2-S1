import mymodule

def print_part1():
  print("VERSION="+str(mymodule.VERSION))
  print("PI="+str(mymodule.PI))
  print("pi()="+str(mymodule.pi()))
  print("PI+5="+str(mymodule.add_pi(5)))
  return

########### MAIN ############"
mymodule.stats()
print_part1()
mymodule.set_log(1);
print_part1();
mymodule.set_log(0);
mymodule.stats();
