# struct-sach
---

# Báo Cáo Phân Tích Mã Nguồn Quản Lý Sách (C Language)

Chương trình thực hiện các chức năng quản lý danh mục sách, cho phép nhập thông tin từ bàn phím và lưu trữ/truy xuất dữ liệu dưới dạng **tệp tin nhị phân (Binary File)**.

## 1. Định nghĩa Cấu trúc Dữ liệu

Chương trình sử dụng một `struct` có tên là `SACH` (định danh `SA`) để đóng gói các thông tin liên quan đến một cuốn sách:

| Thuộc tính | Kiểu dữ liệu | Mô tả |
| --- | --- | --- |
| `ISBN` | `char[11]` | Mã số tiêu chuẩn quốc tế cho sách. |
| `tieude` | `char[110]` | Tên/Tiêu đề của cuốn sách. |
| `tacgia` | `char[30]` | Tên tác giả. |
| `NXB` | `char[110]` | Nhà xuất bản. |
| `loaisach` | `char[50]` | Thể loại sách. |
| `NPH` | `int` | Năm phát hành. |
| `sotrang` | `int` | Tổng số trang sách. |
| `giaban` | `long long` | Giá tiền (sử dụng kiểu số nguyên lớn). |

---

## 2. Các Thành phần Chức năng

### A. Nhập và Xuất (Console)

* **`nhap(SA *a)`**: Thực hiện nhập dữ liệu từ bàn phím cho một đối tượng. Sử dụng `fflush(stdin)` để tránh tình trạng trôi lệnh khi nhập chuỗi sau số.
* **`xuat(SA a)`**: Hiển thị thông tin sách ra màn hình theo định dạng hàng ngang.
* **`nhapn` / `xuatn**`: Các hàm vòng lặp để xử lý danh sách (mảng) nhiều cuốn sách cùng lúc.

### B. Xử lý File Nhị phân

Chương trình sử dụng cơ chế đọc/ghi trực tiếp vùng nhớ vào tệp tin `.out`:

1. **Ghi File (`nhapnfile`)**:
* Sử dụng chế độ `"wb"` (Write Binary).
* Hàm `fwrite` giúp lưu toàn bộ mảng struct xuống đĩa cứng một cách nhanh chóng.


2. **Đọc File (`xuatnfile`)**:
* Sử dụng chế độ `"rb"` (Read Binary).
* Hàm `fread` nạp ngược dữ liệu từ tệp vào bộ nhớ RAM trước khi hiển thị.



---

## 3. Sơ đồ Hoạt động của Chương trình

```mermaid
graph LR
    A[Bàn phím] -->|nhap| B(Mảng Struct)
    B -->|fwrite| C[(File dss.out)]
    C -->|fread| D(Mảng Struct)
    D -->|xuat| E[Màn hình]

```


---

**Bạn có muốn mình hiệu chỉnh lại đoạn code trên để khắc phục các lỗi về định dạng `%lld` và chỉ số mảng không?**
