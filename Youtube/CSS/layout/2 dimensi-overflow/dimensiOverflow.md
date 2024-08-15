# Dimensi dan Overflow dalam CSS

CSS menyediakan berbagai cara untuk mengatur ukuran dan penanganan konten yang meluap dalam elemen HTML. Dua konsep penting yang terkait adalah **dimensi** dan **overflow**.

## Dimensi

Dimensi mengacu pada ukuran elemen di halaman web. CSS menyediakan beberapa properti untuk mengatur dimensi elemen, seperti `width`, `height`, `max-width`, `min-width`, `max-height`, dan `min-height`.

### Properti Dimensi

- **`width`**: Mengatur lebar elemen.
- **`height`**: Mengatur tinggi elemen.
- **`max-width`**: Mengatur lebar maksimum elemen, berguna untuk membuat elemen responsif.
- **`min-width`**: Mengatur lebar minimum elemen.
- **`max-height`**: Mengatur tinggi maksimum elemen.
- **`min-height`**: Mengatur tinggi minimum elemen.

## Satuan untuk Dimensi dalam CSS
## Satuan Absolut (Sering digunakan)

- **`px` (piksel)**: Satuan paling umum digunakan, terutama untuk elemen yang membutuhkan ukuran tetap. Ukuran ini tidak berubah terlepas dari ukuran layar atau resolusi.

## Satuan Relatif

- **`%` (persentase)**: Satuan relatif terhadap elemen induk. Misalnya, `width: 50%` berarti lebar elemen adalah 50% dari elemen induk pembungkusnya.
- **`em`**: Satuan yang relatif terhadap ukuran font elemen induk. Misalnya, `2em` berarti dua kali ukuran font elemen induk.
- **`rem` (root em)**: Sama seperti `em`, tetapi relatif terhadap ukuran font elemen root (biasanya `<html>`). Ini membuat `rem` lebih konsisten dan prediktabel dibandingkan dengan `em`.
- **`vw` (viewport width)**: 1vw sama dengan 1% dari lebar viewport. Cocok untuk desain responsif.
- **`vh` (viewport height)**: 1vh sama dengan 1% dari tinggi viewport.

## Contoh Penggunaan Satuan

```css
.box {
    width: 300px;      /* Lebar 300 piksel */
    height: 50%;       /* Tinggi 50% dari elemen induk */
    font-size: 2em;    /* Ukuran font dua kali ukuran font induk */
    padding: 1rem;     /* Padding sebesar 1 rem */
    margin: 10vw;      /* Margin sebesar 10% dari lebar viewport */
}
```

## Overflow

Overflow terjadi ketika konten dalam elemen lebih besar daripada ruang yang tersedia. Properti overflow digunakan untuk mengontrol bagaimana konten yang meluap ditangani.

### Nilai Overflow

- **`visible`**: (default) Konten yang meluap akan terlihat di luar batas elemen.
- **`hidden`**: Konten yang meluap akan dipotong dan tidak terlihat.
- **`scroll`**: Konten yang meluap akan membuat elemen memiliki scrollbar.
- **`auto`**: Menambahkan scrollbar hanya jika konten meluap.

