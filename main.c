#define _CRT_SECURE_NO_WARNINGS // unsafe uyarılarını kaldırmak için
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>  // setcolor fonksiyonu için
#include <dos.h>	// setcolor fonksiyonu için
#include <locale.h> // setlocale fonksiyonu için
#include <time.h>


void SetColor(int ForgC) // alıntıdır. fonksiyonu oluşturan: stackoverflow.com: maddouri isimli kullanıcı
{
	WORD wColor;

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	//We use csbi for the wAttributes word.
	if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
	{
		//Mask out all but the background attribute, and add in the forgournd color
		wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
		SetConsoleTextAttribute(hStdOut, wColor);
	}
	return;
}

// Birden çok fonksiyonda kullanılacak değişkenler aşağıda tanımlanmıştır.

FILE *websitesi;
char baslik[200] = "Site Başlığı";
char menubaslik[200] = "Menü Başlığı";
char icbaslik[200] = "İç başlık";
int arkaplanrenk = -2;
char *arkaplanrenkhex;
int menublokrenk = -2;
char *menublokrenkhex;
int yaziarkarenk = -2;
char *yaziarkarenkhex;
int konsolrenk = 1;
char ic_metin[2500] = "İyi bir web sitesi olmasını umuyorum.";
char *yorumarkarenkhex;

void arkaplanrenkayarla()
{
	switch (arkaplanrenk)
	{
	case 0:
		arkaplanrenkhex = "000000";
		yorumarkarenkhex = "808080";
		break;
	case 1:
		arkaplanrenkhex = "000080";
		yorumarkarenkhex = "000000";
		break;
	case 2:
		arkaplanrenkhex = "008000";
		yorumarkarenkhex = "000000";
		break;
	case 3:
		arkaplanrenkhex = "008080";
		yorumarkarenkhex = "000080";
		break;
	case 4:
		arkaplanrenkhex = "800000";
		yorumarkarenkhex = "000000";
		break;
	case 5:
		arkaplanrenkhex = "800080";
		yorumarkarenkhex = "000000";
		break;
	case 6:
		arkaplanrenkhex = "808000";
		yorumarkarenkhex = "000000";
		break;
	case 7:
		arkaplanrenkhex = "C0C0C0";
		yorumarkarenkhex = "808080";
		break;
	case 8:
		arkaplanrenkhex = "808080";
		yorumarkarenkhex = "000000";
		break;
	case 9:
		arkaplanrenkhex = "0000FF";
		yorumarkarenkhex = "000080";
		break;
	case 10:
		arkaplanrenkhex = "00FF00";
		yorumarkarenkhex = "008000";
		break;
	case 11:
		arkaplanrenkhex = "00FFFF";
		yorumarkarenkhex = "008080";
		break;
	case 12:
		arkaplanrenkhex = "FF0000";
		yorumarkarenkhex = "800000";
		break;
	case 13:
		arkaplanrenkhex = "FF00FF";
		yorumarkarenkhex = "800080";
		break;
	case 14:
		arkaplanrenkhex = "FFFF00";
		yorumarkarenkhex = "808000";
		break;
	case 15:
		arkaplanrenkhex = "FFFFFF";
		yorumarkarenkhex = "C0C0C0";
		break;
	default:
		printf("Geçersiz arkaplan rengi tespit edildi ilk değer korunuyor.");
		break;
	}
}

void menublokrenkayarla()
{
	switch (menublokrenk)
	{
	case 0:
		menublokrenkhex = "000000";
		break;
	case 1:
		menublokrenkhex = "000080";
		break;
	case 2:
		menublokrenkhex = "008000";
		break;
	case 3:
		menublokrenkhex = "008080";
		break;
	case 4:
		menublokrenkhex = "800000";
		break;
	case 5:
		menublokrenkhex = "800080";
		break;
	case 6:
		menublokrenkhex = "808000";
		break;
	case 7:
		menublokrenkhex = "C0C0C0";
		break;
	case 8:
		menublokrenkhex = "808080";
		break;
	case 9:
		menublokrenkhex = "0000FF";
		break;
	case 10:
		menublokrenkhex = "00FF00";
		break;
	case 11:
		menublokrenkhex = "00FFFF";
		break;
	case 12:
		menublokrenkhex = "FF0000";
		break;
	case 13:
		menublokrenkhex = "FF00FF";
		break;
	case 14:
		menublokrenkhex = "FFFF00";
		break;
	case 15:
		menublokrenkhex = "FFFFFF";
		break;
	default:
		printf("Geçersiz menü bloğu rengi tespit edildi ilk değer korunuyor.");
		break;
	}
}

void yaziarkarenkayarla()
{
	switch (yaziarkarenk)
	{
	case 0:
		yaziarkarenkhex = "000000";
		break;
	case 1:
		yaziarkarenkhex = "000080";
		break;
	case 2:
		yaziarkarenkhex = "008000";
		break;
	case 3:
		yaziarkarenkhex = "008080";
		break;
	case 4:
		yaziarkarenkhex = "800000";
		break;
	case 5:
		yaziarkarenkhex = "800080";
		break;
	case 6:
		yaziarkarenkhex = "808000";
		break;
	case 7:
		yaziarkarenkhex = "C0C0C0";
		break;
	case 8:
		yaziarkarenkhex = "808080";
		break;
	case 9:
		yaziarkarenkhex = "0000FF";
		break;
	case 10:
		yaziarkarenkhex = "00FF00";
		break;
	case 11:
		yaziarkarenkhex = "00FFFF";
		break;
	case 12:
		yaziarkarenkhex = "FF0000";
		break;
	case 13:
		yaziarkarenkhex = "FF00FF";
		break;
	case 14:
		yaziarkarenkhex = "FFFF00";
		break;
	case 15:
		yaziarkarenkhex = "FFFFFF";
		break;
	default:
		printf("Geçersiz yazı arkaplan rengi tespit edildi ilk değer korunuyor.");
		break;
	}
}


void htmlhazirla()
{
	fprintf(websitesi, "<!DOCTYPE html>\n <html>\n <head>\n <meta charset=\"UTF - 8\"/>");
	fprintf(websitesi, "\n<title>%s</title>", baslik);
	// CSS kodu line breaklar "\n" ile değiştirildikten sonra tek satıra dönüştürülüp frpintf ile yazıldı >
	// CSS kodu içerisinde kullanıcı tarafından belirlenen renk bilgilerini tutacak.
	 // Rastgele renkler belirlendikten sonra bu labele dönülecek.
	if (arkaplanrenk == -1)
	{
		srand(time(NULL));
		arkaplanrenk = rand() % 16;
		arkaplanrenkayarla();
	}
	else
	{
		arkaplanrenkayarla();
	}


	if (menublokrenk == -1)
	{
		srand(time(NULL)+1);
		menublokrenk = (rand() % 16);
		menublokrenkayarla();
	}
	else
	{
		menublokrenkayarla();
	}

	if (yaziarkarenk == -1)
	{
		srand(time(NULL)+2);
		yaziarkarenk = (rand() % 16);
		yaziarkarenkayarla();
	}
	else
	{
		yaziarkarenkayarla();
	}

	fprintf(websitesi, "<style>::-webkit-scrollbar { \nwidth: 7px; \n} \n::-webkit-scrollbar-track { \nbackground-color: rgba(125,125,125,0.5); \nborder-radius: 5px; \nbox-shadow: 1px 1px 6px rgba(0,0,0,0.5) inset; \n} \n::-webkit-scrollbar-thumb { \n border-radius: 5px;");
	// Scrollbar rengi menu blok rengi ile uyumlu olacak :
	fprintf(websitesi, "\nbackground: #%s;", menublokrenkhex);
	fprintf(websitesi, "\nl} \n \n:: - webkit - scrollbar - thumb:hover{ \nbackground: #%s;", menublokrenkhex);
	fprintf(websitesi, "\n } \n \n.ic_blok \n{ \n z - index: 1; \n position : fixed; \n left : 0px; \n top : 0px; \n width : 100%%; \n height : 100%%; \n ");
	fprintf(websitesi, "background-color: #%s;", arkaplanrenkhex); // Arkaplan rengi
	fprintf(websitesi, "\n} \n \n.ust_menu \n{ \n z-index: 999; \n position: fixed; \n ");
	//Üst menü rengi aşağıda
	fprintf(websitesi, "background-color: #%s;", menublokrenkhex);
	if (menublokrenk == 1 || menublokrenk == 4 || menublokrenk == 9 || menublokrenk == 0)
	{
		fprintf(websitesi, "\ncolor: #FFFFFF;");
	}
	fprintf(websitesi, "\n width: 50%%; \n left: 50%%; \n transform: translateX(-50%%); \n height: 100px; \n} \n \n.orta_blok \n{ \n overflow: auto; \n margin-top: 100px; \n \n z-index: 2; \n position: fixed; \n left: 50%%; \n transform: translateX(-50%%); \n top: 0px; \n width: 50%%; \n height: 100%%; \n ");
	//Yazı arkaplan rengi aşağıda
	fprintf(websitesi, "background-color:#%s;", yaziarkarenkhex);
	fprintf(websitesi, "\n} \n \n.orta_blok p{ \n ");
	if (yaziarkarenk == 1 || yaziarkarenk == 4 || yaziarkarenk == 9 || yaziarkarenk == 0)
	{
		fprintf(websitesi, "color: #FFFFFF;");
	}
	fprintf(websitesi, "\n margin-bottom: 130px; \n margin-left: 40px; \n font-family: Calibri; \n} \n \n.ust_menu img{ \n position: absolute; \n left: 5%%; \n top: 50%%; \n transform: translate(-5%%,-50%%); \n max-height: 100px; \n \n} \n \n.yorum_bolgesi \n{ \n position: relative; \n bottom: 0px; \n left: 0px; \n width: 100%%; \n height: 500px; \n ");
	// Yorum bolgesi arka plan rengi aşağıda
	fprintf(websitesi, "background-color: #%s;", yorumarkarenkhex);
	if (arkaplanrenk == 7 || arkaplanrenk == 15)
	{
		fprintf(websitesi, "\ncolor: #000000;\n");
	}
	else
	{
		fprintf(websitesi, "\ncolor: #FFFFFF;\n");
	}
	fprintf(websitesi, "\n} \n \n.yorumlar \n{ \n overflow : auto; \n position : relative; \n padding : 15px; \n display : block; \n background-color: inherit; \n width : 95%%; \n height : 200px; \n } \n \nyorum \n{ \n display : block; \n ");
		
		if (arkaplanrenk == 7 || arkaplanrenk == 15)
		{
			fprintf(websitesi, "\ncolor: #000000;\n");
		}
		else
		{
			fprintf(websitesi, "\ncolor: #FFFFFF;\n");
		}
	 fprintf(websitesi, "} \n \n.yorum_yapma_bolgesi \n{ \n display : block; \n background-color: black; \n position : absolute; \n bottom : 0px; \n width : 100%%; \n height : 200px; \n margin-bottom: 30px; \n \n } \n \n.yorum_araclari \n{ \n display : block; \n position : absolute; \n top : 10px; \n left : 50%%; \n \n transform : translateX(-50%%); \n \n } \n \n.site_baslik \n{ \n position : absolute; \n left : 20%%; \n top : 50%%; \n transform : translate(-20%%,-50%%); \n font-size: 36px; \n font-family: sans-serif; \n font-weight: bold; \n \n } \n \n.icerik_baslik \n{ \n font-family: arial black; \n font-size: 24px; \n");
	if (yaziarkarenk == 1 || yaziarkarenk == 4 || yaziarkarenk == 9 || yaziarkarenk == 0)
	{
		fprintf(websitesi, "color: #FFFFFF;");
	}
	fprintf(websitesi, "\n margin-top: 10px; \n margin-bottom: 10px; \n margin-left: 40px; \n}</style> </head> ");
	fprintf(websitesi, "<body> <div class = \"ic_blok\"> <div class=\"ust_menu\"><div class=\"site_baslik\">%s</div> </div>", menubaslik);
	fprintf(websitesi, "<div class=\"orta_blok\"><div class=\"icerik_baslik\">%s</div> ", icbaslik);
	fprintf(websitesi, "<p>	%s <//p> <br> <br>", ic_metin);
	fprintf(websitesi, "<div class=\"yorum_bolgesi\"> <div id=\"yorumlar\" class=\"yorumlar\"> <div align=\"center\" style=\"font-family: 'Calibri'; font-size: 20px; font-weight: bold; \">YORUMLAR</div><br>");
	fprintf(websitesi, "</div> <div class=\"yorum_yapma_bolgesi\"> <div class = \"yorum_araclari\"><input type=\"text\" id=\"isim_kutusu\" placeholder=\"İsminizi girin\" style=\"width: 150px\"><br><br><textarea id=\"mesaj_kutusu\" placeholder=\"Yorum yazın.\" style=\"width: 150px;\"></textarea><button onclick=\"mesajgonder();\" id=\"gonder\" style=\"margin-left: 15px; \">Gönder</button></div>");
	fprintf(websitesi, "<script type=\"text/javascript\">\nvar yorumlar = document.getElementById(\"yorumlar\");\nvar mesaj_kutusu = document.getElementById(\"mesaj_kutusu\");\nvar gonder = document.getElementById(\"gonder\");\nvar isim_kutusu = document.getElementById(\"isim_kutusu\");");
	fprintf(websitesi, "\nfunction mesajgonder()\n{\n	if (isim_kutusu.value != \"\"){\n\nif (mesaj_kutusu.value != \"\") {\n	var yenimesaj = document.createElement(\"yorum\");\n	yenimesaj.innerHTML = \"<b>İsim:</b> \" + isim_kutusu.value + \"<br>\" +\n	\"<b>Yorum:</b> \" + mesaj_kutusu.value + \"<br><br>\";\n	mesaj_kutusu.value = \"\";\n	isim_kutusu.value = \"\";\n	yorumlar.appendChild(yenimesaj);\n}\nelse\n{\n	alert(\"Yorum yazmadınız.\");\n}\n}\n	else{\n		alert(\"İsminizi girmediniz.\");\n	}\n}\n</script>");
	fprintf(websitesi, "</div></div></div></div></body></html>");

}




void main()
{
	setlocale(LC_ALL, "Turkish"); // türkçe karakterleri kabul et.

	system("echo %USERPROFILE:\\=\\\\%\\\\Desktop\\\\WebSiteniz.html > masaüstü.txt"); // masaüstü konumunu cmd üzerinden bul ve masaüstü.txt'ye kaydet.
	// bu komut dizin adresinden sonra bir boşluk ve bir de alt satır ekler.

	char masaüstü[1024];

	FILE *masaüstütxt = fopen("masaüstü.txt", "r"); // masaüstü.txt dosyasını reading modunda aç.
	fgets(masaüstü, 1024, masaüstütxt); // masaüstütxt den 1024 karakter oku masaüstü değişkenine ata.

	int sonkarakter = 1024;

	for (int i = 0; i < 1024; i++)
	{
		if (masaüstü[i] == '\0')
		{
			sonkarakter = i-1;  // ilk boş karakter i no'lu elemanda bulunur 
			// i no lu elemandan önceki karakter alt satıra geçiş karakteri ileride silinecek.
			// alt satıra geçiş karakterinden önceki eleman boşluk karakteri ileride silinecek.
			break;
		}

	}

	masaüstü[sonkarakter] = '\0'; // alt satıra geçiş karakteri boş karakter ile değiştirildi.
	masaüstü[sonkarakter - 1] = '\0'; // boşluk karakteri boş karakter ile değiştirdili.

	printf("Oluşturacağınız web sitesi masaüstüne kaydedilecek.");
	fclose(masaüstütxt);
	remove("masaüstü.txt");



	websitesi = fopen(masaüstü, "w");

	if (websitesi == NULL)
	{
		printf("\nGörünüşe göre masaüstünde daha önce bir dosya oluşturulmuş.\nÜzerine yazmak için 1 çıkış yapmak için 0 girin.");
		int tercih;
		scanf("%d", &tercih);
		switch (tercih)
		{
		case 1:
		{
			remove(masaüstü);
			websitesi = fopen(masaüstü, "w");
			break;
		}
		case 0:
			exit(0);
			break;
		default:
		{
			printf("\n Hatalı değer girildi çıkılıyor.");
			system("Pause");
			exit(0);
			break;
		}
		}
	}
	else
	{
		printf("\nDosya açma başarılı\n");
	}

		printf("Siteniz için renk şeması seçin.Siyah için 0 ,Rastgele renk için -1 girin.\n\n ");
		for (int i = 1; i <= 13; i+=3)
		{
			SetColor(i); printf("Renk %d ", i); SetColor(i + 1); printf("Renk %d ", i + 1); SetColor(i + 2); printf("Renk %d\n ", i + 2);
		}
		SetColor(7);
		while (arkaplanrenk < -1 || arkaplanrenk > 15) {
			printf("\nKarar verdiğiniz arkaplan renk numarasını girin[ -1 ... 15]: ");
			scanf("%d", &arkaplanrenk);
		}
		while (menublokrenk < -1 || menublokrenk > 15) {
			printf("\nMenu bloğu için renk numarası giriniz [-1 ... 15]: ");
			scanf("%d", &menublokrenk);
		}
		while (yaziarkarenk < -1 || yaziarkarenk > 15) {
			SetColor(14);
			printf("\nYazı rengi seçeceğiniz arkaplan rengine uyumlu olarak siyah veya beyaz olacaktır\n");
			SetColor(7);
			printf("Yazılar için arkaplan rengi seçiniz[-1 ... 15]: ");
			scanf("%d", &yaziarkarenk);
		}
		system("cls");
		SetColor(12);
		printf("\n\tLütfen bu aşamadan sonra TÜRKÇE karakter KULLANMAYIN\n");
		SetColor(7);
		printf("\nGözükecek sekme başlığını girin: ");
		gets(baslik); gets(baslik);
		SetColor(12);
		printf("\n\tArtık web sitenizin gövde kısmına yazıyorsunuz.\n\tHTML tagleri kullanabilirsiniz fakat halen Türkçe\n\tkarakter kullanmamalısınız.\n");
		SetColor(7);
		printf("\nWeb sayfanızda üst menüde gözükecek site başlığını girin: ");
		gets(menubaslik);
		printf("\nWeb sayfanızın içeriğinde görüntülenecek metin için başlık girin: ");
		gets(icbaslik);
		printf("\nWeb sayfanızın içeriğinde görüntülenecek metni girin: ");
		gets(ic_metin);

		htmlhazirla();

		fclose(websitesi);

		SetColor(10);
		printf("\n \n \t Web siteniz masaüstüne kayıt edildi.\n ");
		system("PAUSE >nul | set /p=Programdan çıkmak ve sitenizi açmak için herhangi bir tuşa basın.");
		system(masaüstü);

	}
