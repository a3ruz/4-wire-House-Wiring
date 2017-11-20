void l_slavewrite()//passes slave address , device number ,and last state of device 
{
  int i;
  byte L_slave_1[4];
  byte L_slave_2[4];
  
  for(i=0;i<5;i++)
  {
     L_slave_1[i]=l_slave_array[0][i];
  }
Wire.beginTransmission(L_SLAVE_1); // selects the slave 
  Wire.write(L_slave_1,4);              // sends device address  
  Wire.endTransmission();
  
  for(i=0;i<5;i++)
  {
     L_slave_2[i]=l_slave_array[1][i];
  }
  
Wire.beginTransmission(L_SLAVE_2); // selects the slave 
  Wire.write(L_slave_2,4);              // sends device address  
  Wire.endTransmission();
  
    
}
