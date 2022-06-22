import serial       
import time
from tkinter import Tk,Label,Button,Entry

serialArduino = serial.Serial("COM3",9600,timeout=1.0)
#timeout (1 segundo) o tiempo máximo de espera para una lectura.
time.sleep(1) # espera 1 seg, para dar tiempoa conectarse

while True:
     #cad =serialArduino.readline().decode('ascii') 

     cad =serialArduino.readline().decode('ascii').strip()
     Dista= cad[11:16] 
     Temp= cad[22:27] 
     Hum= cad[33:]  
     
     vent = Tk()
     vent.title("Ejemplo place")
     vent.geometry("400x200")
     
     def fSuma():
          txtNum1.delete(0,'end')
          txtNum1.insert(0,Dista)
          txtNum2.delete(0,'end')
          txtNum2.insert(0,Temp)
          txtNum3.delete(0,'end')
          txtNum3.insert(0,Hum)    
    

     lblNum1 = Label(vent,text="Distancia: ",bg="yellow")
     txtNum1=Entry(vent,bg="pink")
     lblNum2 = Label(vent,text="Temperatura: ",bg="yellow")
     txtNum2=Entry(vent,bg="pink")
     lblNum3 = Label(vent,text="Humedad: ",bg="yellow")
     txtNum3=Entry(vent,bg="cyan")
     btn1=Button(vent,text="Estado", command=fSuma)


     lblNum1.pack(pady=6)
     txtNum1.pack(pady=6)
     lblNum2.pack(pady=6)
     txtNum2.pack(pady=6)
     lblNum3.pack(pady=6)
     txtNum3.pack(pady=6)
     btn1.pack(pady=6)

     vent.mainloop()