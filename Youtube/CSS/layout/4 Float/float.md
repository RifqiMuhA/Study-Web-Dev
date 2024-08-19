# Float

Float merupakan properti CSS untuk mengatur posisi sebuah elemen agar dapat dipaksa untuk berada di sebelah kiri / kanan parent. Float memungkinkan elemen lain flow di sekitar elemen tersebut.

## Nilai Float
Nilai Float
none (Nilai default) : Elemen tidak mengapung.
left: Mengapung elemen ke sebelah kiri kontainer.
right: Mengapung elemen ke sebelah kanan kontainer.
inherit: Elemen mewarisi nilai float dari elemen induknya.

- `none` (Nilai default) : Elemen tidak mengapung.
- `left` : Mengapung elemen ke sebelah kiri kontainer.
- `right` : Mengapung elemen ke sebelah kanan kontainer.
- `inherit` : Elemen mewarisi nilai float dari elemen induknya.

# Clear

Properti `clear` digunakan untuk mengontrol perilaku elemen setelah elemen yang mengapung. Properti ini berguna untuk mencegah elemen lain mengalir di sekitar elemen yang mengapung, mengembalikan tata letak dokumen ke kondisi normal setelah elemen mengapung.

## Nilai Clear

- `left`: Elemen akan dipindahkan di bawah elemen yang mengapung ke kiri.
- `right`: Elemen akan dipindahkan di bawah elemen yang mengapung ke kanan.
- `both`: Elemen akan dipindahkan di bawah elemen yang mengapung ke kiri dan kanan.
- `none`: Nilai default; elemen tidak dipindahkan.
- `inherit`: Elemen mewarisi nilai clear dari elemen induknya.

# Contoh
```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
        .box {
            width: 200px;
            height: 100px;
            margin: 10px;
            background-color: lightgreen;
        }

        .float-left {
            float: left;
        }

        .clearfix {
            clear: both;
        }
    </style>
    <title>Clear Example</title>
</head>
<body>
    <div class="box float-left">Float Left</div>
    <div class="box float-left">Float Left</div>
    <div class="clearfix"></div>
    <p>This paragraph is below the floated elements due to clear: both.</p>
</body>
</html>
```

# Kegunaan

1. Text wrapping
   Membuat text mengelilingi gambar / elemen lain
2. Image gallery
   Membuat serangkaian gambar menjadi galeri
3. Multi-column layout
   Membuat halaman memiliki beberapa kolom


## Poin Penting
1. elemen yg diberikan float akan dipaksa ditempatkan pada kiri atau kanan sesuai valuenya.
2. posisinya hanya bisa di kanan atau kiri saja dari pembungkus, bisa 
gunakn position namun elemen html teks  akan menganggap float tersebut posisinya sama seperti semula (wrappingnya tidak mengelilingi elemen float yang diberi properti position non static)
3. elemen yg diterapkan float letaknya setelah elemen html sebelumnya yg tidak diberi float
(sesuai susunan kode yg kalian tulis pada html)
4. elemen yg diterapkan float akan keluar dari flow normal (seperti dimensi baru)
5. float bisa ditaruh secara berjejer (seperti foto galeri) jika elemen secara berurutan
diberikan float. apabila pada urutan elemen tsb ada yg tidak diberi float maka
elemen float setelahnya akan ditempatkan pada flow-float yang baru
6. elemen yg diberi float akan dianggap tidak ada pada struktur html
membuat elemen dibawahnya terdorong ke atas (dianggap tak ada)
7.  jika elemen setelah elemen float terdapat teks, maka teks tersebut
akan menganggap elemen float tersebut eksis, maka dari itu reaksinya
adalah mengelilingi elemen tersebut/wrapping (special css rule)
8. karena poin nomer 6, ketika float digunakan pada elemen yang terdapat
pada container akan terjadi container collapse namun bisa 
diperbaiki dengan properti clear
9. ketika digunakan clear maka elemen yang atau setelah diterapkan 
properti clear akan memasuki float-flow yang baru