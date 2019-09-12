from decimal import Decimal, getcontext
import time


start_time = time.time()

N = 10 # Precision

# Calculo de PI

getcontext().prec = N

print sum(1/Decimal(16)**k * 
          (Decimal(4)/(8*k+1) - 
           Decimal(2)/(8*k+4) - 
           Decimal(1)/(8*k+5) -
           Decimal(1)/(8*k+6)) for k in range(N))

print("--- %s segundos ---" % (time.time() - start_time))

