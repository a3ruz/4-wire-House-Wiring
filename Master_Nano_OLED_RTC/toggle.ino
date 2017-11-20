//check byte Tdevice[] and make chages 
// l_slave_array[0][i] array being send to the light slaves

void toggle()
{
 // Serial.println("TOGGLE FUNCTION");
  int td,slavea,slavedevice;
  slavea=0;
  slavedevice=0;
  for(td=0;td<5;td++)
  {
    if(Tdevice[td]==1)
    if(l_slave_array[slavea][slavedevice]==0)
    {
    l_slave_array[slavea][slavedevice]=1;
    Tdevice[td]=0;
    }
     if(l_slave_array[slavea][slavedevice]==1)
     {
      if(Tdevice[td]==1)
      l_slave_array[slavea][slavedevice]=0;
      Tdevice[td]=0;
     }
     
    slavedevice++;
  }
  



slavea=1;
  slavedevice=0;
  for(td=5;td<9;td++)
  {
    if(Tdevice[td]==1&&l_slave_array[slavea][slavedevice]==1)
  l_slave_array[slavea][slavedevice]=0;

if(Tdevice[td]==1&&l_slave_array[slavea][slavedevice]==0)
l_slave_array[slavea][slavedevice]=1;
slavedevice++;
  }
/*for(td=0;td<5;td++)
{
  Serial.print( Tdevice[td]);
Serial.print(l_slave_array[0][td]);

}
Serial.println();
*/
}

