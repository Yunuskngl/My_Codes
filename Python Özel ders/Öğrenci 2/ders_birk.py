{
 "cells": [
  {
   "cell_type": "code",
   "execution_count": 4,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "5\n"
     ]
    }
   ],
   "source": [
    "#Print fonksiyonu çıktı almamızı sağlayan fonksiyondur.\n",
    "\n",
    "print(5)  #tam sayı   (int)  integer"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 6,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "5.3\n"
     ]
    }
   ],
   "source": [
    "print(5.3)  #ondalıklı sayı (float)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 7,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "dersimize başladık\n"
     ]
    }
   ],
   "source": [
    "print(\"dersimize başladık\") #string  (str)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 8,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "<class 'str'>\n"
     ]
    }
   ],
   "source": [
    "print(type(\"dersimize başladık\"))   #type fonksiyonu hangi tür olduğunu belirtir."
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 53,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "<class 'int'>\n"
     ]
    }
   ],
   "source": [
    "sayı = 5\n",
    "\n",
    "print(type(sayı))"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 10,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "<class 'float'>\n"
     ]
    }
   ],
   "source": [
    "print(type(5.42342))"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 58,
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/plain": [
       "10"
      ]
     },
     "execution_count": 58,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "5+5 #toplama işlemi"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 13,
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/plain": [
       "3"
      ]
     },
     "execution_count": 13,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "5-2 #çıkarma işlemi"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 15,
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/plain": [
       "15"
      ]
     },
     "execution_count": 15,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "5*3 #çarpma işlemi"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 18,
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/plain": [
       "3.5"
      ]
     },
     "execution_count": 18,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "7/2 #bölme işlemi\n"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 51,
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/plain": [
       "3"
      ]
     },
     "execution_count": 51,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "10//3 #bölme işlemi sonucunu tam sayı olarak verir."
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 26,
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/plain": [
       "2"
      ]
     },
     "execution_count": 26,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "17%3 #mod alma işlemi\n"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 29,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "5\n"
     ]
    }
   ],
   "source": [
    "#Bu bir yorum satırıdır. Satır şeklinde not tutmak için kullanılır\n",
    "\n",
    "\"\"\"  \n",
    "Bu bir yorum satırıdır. Paragraf şeklinde not tutmak için kullanılır\n",
    "\"\"\"\n",
    "print(5)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 38,
   "metadata": {},
   "outputs": [],
   "source": [
    "x  = 5.2   #değişken tanımlama\n",
    "y = 10"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 39,
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/plain": [
       "15.2"
      ]
     },
     "execution_count": 39,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "x+y  # int  +  float  = float\n"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 40,
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/plain": [
       "60.4"
      ]
     },
     "execution_count": 40,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "2*x + 5*y   "
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 44,
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/plain": [
       "27"
      ]
     },
     "execution_count": 44,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "m = 3\n",
    "m**3  #üs değeri almak için."
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 46,
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/plain": [
       "-5"
      ]
     },
     "execution_count": 46,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "r = 5 \n",
    "-r #negatif olarak çevirir. - - = + olur."
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 48,
   "metadata": {},
   "outputs": [],
   "source": [
    "4u = 150   # değişken ismi koyarken (tanımlarken) bir harfin önüne sayı koyamayız. ancak harfin sonuna koyabiliriz."
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 49,
   "metadata": {},
   "outputs": [],
   "source": [
    "pi = 3.14\n",
    "r = 10\n",
    "çevre = pi * r    #31.4 değerine eşit oldu\n"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 50,
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/plain": [
       "31.400000000000002"
      ]
     },
     "execution_count": 50,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "çevre"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 52,
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/plain": [
       "243"
      ]
     },
     "execution_count": 52,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "3**5"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": null,
   "metadata": {},
   "outputs": [],
   "source": []
  },
  {
   "cell_type": "code",
   "execution_count": 2,
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/plain": [
       "205"
      ]
     },
     "execution_count": 2,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "songül = 5  \n",
    "songül = songül + 100  #songül değişkenine 100 ekledik.\n",
    "songül += 100  \n",
    "songül"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 4,
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/plain": [
       "1000"
      ]
     },
     "execution_count": 4,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "sayı = 10\n",
    "sayı = sayı * 10 \n",
    "sayı*= 10   #sayıyı 10 ile çarptık\n",
    "sayı"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 9,
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/plain": [
       "0"
      ]
     },
     "execution_count": 9,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "sayı1 = 10\n",
    "sayı1 = sayı1 -5 \n",
    "sayı1 -= 5   #sayıdan 5 çıkardık\n",
    "sayı1"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 10,
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/plain": [
       "5.0"
      ]
     },
     "execution_count": 10,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "sayı2 = 20 \n",
    "sayı2 = sayı2/2\n",
    "sayı2 /=2  #sayıyı 2 ye böldük\n",
    "sayı2"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": null,
   "metadata": {},
   "outputs": [],
   "source": []
  },
  {
   "cell_type": "code",
   "execution_count": 16,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "merhaba\n"
     ]
    }
   ],
   "source": [
    "cumle = \"merhaba\"\n",
    "print(cumle)  "
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 17,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "merhaba\n"
     ]
    }
   ],
   "source": [
    "cumle = 'merhaba'\n",
    "print(cumle)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 18,
   "metadata": {},
   "outputs": [
    {
     "ename": "SyntaxError",
     "evalue": "EOL while scanning string literal (3984607820.py, line 1)",
     "output_type": "error",
     "traceback": [
      "\u001b[0;36m  Cell \u001b[0;32mIn[18], line 1\u001b[0;36m\u001b[0m\n\u001b[0;31m    cumle = \"merhaba'\u001b[0m\n\u001b[0m                     ^\u001b[0m\n\u001b[0;31mSyntaxError\u001b[0m\u001b[0;31m:\u001b[0m EOL while scanning string literal\n"
     ]
    }
   ],
   "source": [
    "cumle = \"merhaba'  \n",
    "print(cumle)   #bu şekilde yazım hatalıdır"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 19,
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/plain": [
       "'p'"
      ]
     },
     "execution_count": 19,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "dizi = \"pyhton programlama dili\"   #index = bir dizinin içindeki harfin sırası\n",
    "print(dizi[0])    "
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 24,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "t\n"
     ]
    }
   ],
   "source": [
    "print(dizi[3])   #dizi[3] dediğimizde 3.indexteki harfi yazdırır."
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 23,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "p\n"
     ]
    }
   ],
   "source": [
    "print(dizi[7])  ##dizi[7] dediğimizde 7.indexteki harfi yazdırır."
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 25,
   "metadata": {},
   "outputs": [
    {
     "ename": "TypeError",
     "evalue": "'str' object does not support item assignment",
     "output_type": "error",
     "traceback": [
      "\u001b[0;31m---------------------------------------------------------------------------\u001b[0m",
      "\u001b[0;31mTypeError\u001b[0m                                 Traceback (most recent call last)",
      "Cell \u001b[0;32mIn[25], line 1\u001b[0m\n\u001b[0;32m----> 1\u001b[0m \u001b[43mdizi\u001b[49m\u001b[43m[\u001b[49m\u001b[38;5;241;43m3\u001b[39;49m\u001b[43m]\u001b[49m \u001b[38;5;241m=\u001b[39m \u001b[38;5;124m\"\u001b[39m\u001b[38;5;124ma\u001b[39m\u001b[38;5;124m\"\u001b[39m\n\u001b[1;32m      2\u001b[0m \u001b[38;5;28mprint\u001b[39m(dizi)\n",
      "\u001b[0;31mTypeError\u001b[0m: 'str' object does not support item assignment"
     ]
    }
   ],
   "source": [
    "dizi[3] = \"a\" # bu şekilde yazıldığında değpiştirilemez.\n",
    "print(dizi)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 26,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "to\n"
     ]
    }
   ],
   "source": [
    "print(dizi[3:5])  #3 ve 5. index arasındaki kelime parçasını veriyor. ama 5. index dahil değil"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 28,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "prog\n"
     ]
    }
   ],
   "source": [
    "print(dizi[7:11]) #7 ve 11.index değerleri arasındaki kelime parçasını verir.11.index dahil değil!!"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 29,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "por\n"
     ]
    }
   ],
   "source": [
    "print(dizi[7:12:2])  #7. index ile 12. index arasını 2şer li atlayarak yazdırır."
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 33,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "i\n"
     ]
    }
   ],
   "source": [
    "dizi = \"pyhton programlama dili\" # sondan başlarken -1 ile başlar ve böyle giderek devam eder.\n",
    "print(dizi[-3])"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 34,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "60\n"
     ]
    }
   ],
   "source": [
    "dizi1 = \"akmslkdmalkmdslkamdlkasmdlkmaslkdmaslkmdlkamdklmsalkdmaslkdm\"\n",
    "print(len(dizi1))   #len fonksiyonu karakter dizilerinin uzunluğunu ölçer."
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 35,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "3\n"
     ]
    }
   ],
   "source": [
    "dizi2 = \"h e\" #3 karakterlidir. Len fonksiyonu ile kontrol edince 3 değerini verir.\n",
    "print(len(dizi2))"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 39,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "yunus ve songül ders işliyor\n"
     ]
    }
   ],
   "source": [
    "a = \"yunus \"  #str \n",
    "b = \"ve \"      #str \n",
    "c = \"songül \"   #str \n",
    "d = \"ders işliyor\" #str \n",
    "print(a+b+c+d)   # bu şekilde karakter dizilerini birleştirebiliyoruz."
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 41,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "merhaba merhaba merhaba \n"
     ]
    }
   ],
   "source": [
    "e = \"merhaba \"\n",
    "print(e*3) # karakter dizisini bir sayı ile çarparsak bunu tekrar olarak algılayıp bu şekilde yazar."
   ]
  },
  {
   "cell_type": "code",
   "execution_count": null,
   "metadata": {},
   "outputs": [],
   "source": []
  },
  {
   "cell_type": "code",
   "execution_count": null,
   "metadata": {},
   "outputs": [],
   "source": [
    "#str  ,  int , float \n",
    "#karakter dönüşümü "
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 42,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "3\n"
     ]
    }
   ],
   "source": [
    "a = 3.14 #float sayımız.\n",
    "print(int(a)) #bu şekilde karakter dönüşümü yapıp yazdırabiliriz."
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 43,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "7\n"
     ]
    }
   ],
   "source": [
    "print(int(7.555551232131)) #float değeri tam sayıya çevirme"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 44,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "10.0\n"
     ]
    }
   ],
   "source": [
    "print(float(10)) #tam sayıyı float değere çevirme"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 47,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "<class 'str'>\n"
     ]
    }
   ],
   "source": [
    "a= str(101)   #integer bir değişkeni string'e çevirme\n",
    "print(type(a))  "
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 50,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "123214123214\n"
     ]
    }
   ],
   "source": [
    "a = \"123214123214\"   #string bir değişkeni integer'a çevirme\n",
    "print(int(a))"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": null,
   "metadata": {},
   "outputs": [],
   "source": []
  },
  {
   "cell_type": "code",
   "execution_count": 52,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "1 2 3 4 5 6\n"
     ]
    }
   ],
   "source": [
    "print(1,2,3,4,5,6) #print içinde virgül kullanarak bu şekilde yazarsak boşluklu verir."
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 58,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "1*2*3*4*5*6\n"
     ]
    }
   ],
   "source": [
    "print(1,2,3,4,5,6,sep=\"*\") #seperator (ayırıcı) yani sep = \" \" ne yazarsak arasına onu koyar."
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 59,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "1\n",
      "2\n",
      "3\n",
      "4\n",
      "5\n"
     ]
    }
   ],
   "source": [
    "print(1,2,3,4,5,sep=\"\\n\")  #\\n alt satıra geçmesini sağlar."
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 61,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "1\t2\t3\t4\t5\n"
     ]
    }
   ],
   "source": [
    "print(1,2,3,4,5,sep=\"\\t\")  #1 tab boşluğu bırakarak yazdırır."
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 1,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "3.14 5 10\n"
     ]
    }
   ],
   "source": [
    "#FORMATLAMA \n",
    "\n",
    "print(\"{} {} {}\".format(3.14,5,10))"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 4,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "5 + 3 'nin toplamı 9 'dır \n"
     ]
    }
   ],
   "source": [
    "print(\"{} + {} 'nin toplamı {} 'dır \".format(5,3,9))"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 6,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      " 3.151\n"
     ]
    }
   ],
   "source": [
    "print(\" {:.3f}\".format(3.15124131)) "
   ]
  },
  {
   "cell_type": "code",
   "execution_count": null,
   "metadata": {},
   "outputs": [],
   "source": []
  },
  {
   "cell_type": "code",
   "execution_count": null,
   "metadata": {},
   "outputs": [],
   "source": [
    "#listeler  = birden fazla değişkeni aynı yerde tutan yapı."
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 12,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "[1, 2, 3, 4, 5, 'songül', 3.14]\n"
     ]
    }
   ],
   "source": [
    "liste = [1,2,3,4,5,\"songül\",3.14]\n",
    "print(liste)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 13,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "1\n"
     ]
    }
   ],
   "source": [
    "print(liste[0])"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 14,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "songül\n"
     ]
    }
   ],
   "source": [
    "print(liste[5])"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 17,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "[3, 4, 5, 'songül']\n"
     ]
    }
   ],
   "source": [
    "print(liste[2:6])"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 18,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "3.14\n"
     ]
    }
   ],
   "source": [
    "print(liste[-1])"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 19,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "['songül']\n"
     ]
    }
   ],
   "source": [
    "print([liste[-2]])"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 30,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "4\n"
     ]
    }
   ],
   "source": [
    "liste = [1,2,3,4,5,\"songül\",3.14,3,32,4,234,23,423,423,4]\n",
    "print(liste[len(liste)-1])"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 31,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "[4, 423, 423, 23, 234, 4, 32, 3, 3.14, 'songül', 5, 4, 3, 2, 1]\n"
     ]
    }
   ],
   "source": [
    "print(liste[::-1])   #tersten yazdırmak için kullanılıyor.\n"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 35,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "[4, 423, 234, 32, 3.14, 5, 3, 1]\n"
     ]
    }
   ],
   "source": [
    "print(liste[::-2])\n"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 38,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "[5, 6, 10, 7, 8, 9]\n"
     ]
    }
   ],
   "source": [
    "liste1 = [7,8,9]\n",
    "liste2 = [5,6,10]\n",
    "liste3 = liste2 + liste1\n",
    "print(liste3)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 42,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "[5, 6, 10, 7, 8, 9, 'yunus']\n"
     ]
    }
   ],
   "source": [
    "print(liste3 + [\"yunus\"])"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 43,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "[5, 6, 10, 7, 8, 9]\n"
     ]
    }
   ],
   "source": [
    "print(liste3)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": null,
   "metadata": {},
   "outputs": [],
   "source": []
  },
  {
   "cell_type": "code",
   "execution_count": null,
   "metadata": {},
   "outputs": [],
   "source": [
    "#listelerde eleman ekleme ve çıkarmak için metod dediğimiz yapıları kullancaz."
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 44,
   "metadata": {},
   "outputs": [],
   "source": [
    "liste1 = [7,8,9]\n",
    "liste2 = [5,6,10]\n",
    "liste3 = liste2 + liste1"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 45,
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/plain": [
       "[5, 6, 10, 7, 8, 9, 'yunus']"
      ]
     },
     "execution_count": 45,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "liste3.append(\"yunus\")  #sonradan eleman eklemek için kullanılır.\n",
    "liste3"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 46,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "[5, 6, 7, 8, 9, 'yunus']\n"
     ]
    }
   ],
   "source": [
    "liste3.remove(10)  #sonradan eleman eklemek için kullanılır.\n",
    "print(liste3)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 48,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "merhaba\n"
     ]
    }
   ],
   "source": [
    "\"\"\"\n",
    "Liste dediğimiz yapı nedir ? \n",
    "\n",
    "liste dediğimiz yapı [] köşeli parantezle tanımlanıyor.\n",
    "farklı farklı veri tiplerindeki(int , str,float ) elemanları bir arada tutmak için kullanılıyor.\n",
    "\n",
    "\n",
    "\"\"\"\n",
    "\n",
    "\n"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 52,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "[0, 1, 100, 123, 124, 213, 241, 1243]\n"
     ]
    }
   ],
   "source": [
    "liste3 = [123,213,241,124,1243,1,0,100]\n",
    "liste3.sort()\n",
    "print(liste3)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 55,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "[1, 1, 1, 100, 0, 1, 1243, 124, 241, 213, 123]\n"
     ]
    }
   ],
   "source": [
    "liste3 = [123,213,241,124,1243,1,0,100,1,1,1]\n",
    "liste3.reverse()\n",
    "print(liste3)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 58,
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/plain": [
       "4"
      ]
     },
     "execution_count": 58,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "liste3.count(1)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": null,
   "metadata": {},
   "outputs": [],
   "source": []
  }
 ],
 "metadata": {
  "kernelspec": {
   "display_name": "Python 3",
   "language": "python",
   "name": "python3"
  },
  "language_info": {
   "codemirror_mode": {
    "name": "ipython",
    "version": 3
   },
   "file_extension": ".py",
   "mimetype": "text/x-python",
   "name": "python",
   "nbconvert_exporter": "python",
   "pygments_lexer": "ipython3",
   "version": "3.9.6"
  }
 },
 "nbformat": 4,
 "nbformat_minor": 2
}
