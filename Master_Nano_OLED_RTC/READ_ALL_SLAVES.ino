void read_all_slaves()
{
  /*/////////////////////////// READING FROM SLAVE  21 /////////////////////////////*/
  Wire.requestFrom(S_SLAVE_1,6);    // request 6 bytes from slave device #21
 slave_n=0 ;
 switch_n=0;
 Serial.println("FROM S_SLAVE_1 ");
  while (Wire.available()) { // slave may send less than requested
     
     slave_reads[slave_n][switch_n]=Wire.read(); //// receive a byte as character  
    Serial.print(slave_reads[slave_n][switch_n]);         // print the character
  Serial.print(" ");
  switch_n++; 
}
  Serial.println(" ");


  /*/////////////////////////// READING FROM SLAVE 22 /////////////////////////////*/
  Wire.requestFrom(S_SLAVE_2,6);    // request 6 bytes from slave device #22
 slave_n=1 ;
  switch_n=0;
  Serial.println("FROM S_SLAVE_2 "); 
  while (Wire.available()) { // slave may send less than requested
        
     slave_reads[slave_n][switch_n]=Wire.read(); //// receive a byte as character  
 
    Serial.print(slave_reads[slave_n][switch_n]);         // print the character
  Serial.print(" ");
  switch_n++; 
}
 Serial.println(); 




}

