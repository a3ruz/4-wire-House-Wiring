
void set_toggle()
{
  int dcount=0;
 for(slave_n=0;slave_n<2;slave_n++) 
 {
  for(device_n=1 ; device_n<5 ; device_n++)
 {
 if(slave_reads[slave_n][device_n]==1)
{
  Tdevice[dcount]=1;
   dcount++;
}
else
{
  Tdevice[dcount]=0;
   dcount++;
  
}
}
}
}

