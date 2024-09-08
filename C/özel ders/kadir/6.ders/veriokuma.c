#include <stdio.h>
#include <stdlib.h>

int main()
{   /*
    FILE Yapısı file pointer olarak adlandırılır

    FILE *dosya;    şeklinde tanımlanır.


    Dosyayı açmak için fopen(),
    Dosyayı kapatmak için fclose(), kullanılır


    FILE *dosya;
    dosya=fopen(const char dosya_adi,const char mod);
    ....
    dosyaislemleri
    .....
    fclose(dosya);

    DosyaacmaModları

    r       ReadOnly     Sadece okuma için.Dosyanın açılabilmesi için önceden oluşturulması gerekir

    w       WriteOnly    Yanlızca yazma için. Dosya kayıtlı olsun veya olmasın yeniden oluşturulur

    a       append        Ekleme.Kayıtlı bir dosyanın sonuna veri eklemek için kullanılır.

    r+      Okuma ve Yazma  Bu modda açılmış olan bir dosyanın daha önceden var olması gerekir.

    w+      Okuma ve Yazma  Bu modda açılmış olan bir dosya var olsun veya olmasın yeniden oluşturulur.

    a+      Okuma ve Yazma    Kayıtlı bir dosyanın sonuna veri eklemek için açılır


    Fonksiyon

    fgetc()   Dosyaya bir karakter veri okur
    fgets()   Dosyaya bir karakter dizi okur
    fread()   Dosyaya bir kayıt dizi veya karakteri ikili olarak okur
    fscanf()  Dosyadaki verileri biçimlendirerek okur

    DOSYANIN SONUNUN BELİRENMESİ feof()

    Dosyadan okuma işlemleri yapılırken,çoğu kez dosyanın sonunu denetlemek gerekecektir.Dosya
    göstergesinin dosyanın sonuna işaret edip etmediğini anlamak için feof fonksiyonu kullanılır
*/
    FILE *dosya;
    while(!feof(dosya))
    {
        fgetc(dosya);      //  Dosyanın sonuna gelinmediği sürece dosyadan karakter okur

    }

}
