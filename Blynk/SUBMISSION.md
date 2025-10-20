# 📤 แบบฟอร์มส่งงาน: ESP32-S3 + Blynk IoT

<div align="center">

## 🎓 สาขาวิชาวิศวกรรมเครื่องกล ME6831
## 🏛️ มหาวิทยาลัยกาฬสินธุ์
## 📅 ภาคการศึกษา 1/2568

---

### 👨‍🏫 อาจารย์ผู้สอน: ภูริ จันทิมา

</div>

---

## 📝 ข้อมูลนักศึกษา

<table>
<tr>
<td width="200"><b>🎓 ชื่อ-นามสกุล:</b></td>
<td width="400"><code>______________________________________</code></td>
</tr>
<tr>
<td><b>🆔 รหัสนักศึกษา:</b></td>
<td><code>______________________________________</code></td>
</tr>
<tr>
<td><b>📧 อีเมล:</b></td>
<td><code>______________________________________</code></td>
</tr>
<tr>
<td><b>📱 เบอร์โทรศัพท์:</b></td>
<td><code>______________________________________</code></td>
</tr>
<tr>
<td><b>📅 วันที่ส่งงาน:</b></td>
<td><code>______________________________________</code></td>
</tr>
</table>

---

## 📋 Checklist การส่งงาน

### ✅ ไฟล์ที่ต้องส่ง

<table>
<thead>
<tr>
<th width="50">ลำดับ</th>
<th width="300">รายการ</th>
<th width="150">สถานะ</th>
<th>หมายเหตุ</th>
</tr>
</thead>
<tbody>
<tr>
<td align="center">1</td>
<td>📄 <b>โค้ด Arduino (.ino)</b></td>
<td>☐ ส่งแล้ว</td>
<td>ชื่อไฟล์: <code>ESP32_[ชื่อของคุณ].ino</code></td>
</tr>
<tr>
<td align="center">2</td>
<td>📸 <b>รูปถ่ายวงจร</b></td>
<td>☐ ส่งแล้ว</td>
<td>ความละเอียดชัด เห็นการต่อสายทั้งหมด</td>
</tr>
<tr>
<td align="center">3</td>
<td>🖼️ <b>Screenshot Dashboard</b></td>
<td>☐ ส่งแล้ว</td>
<td>แสดง Widgets ทั้งหมด ขณะออนไลน์</td>
</tr>
<tr>
<td align="center">4</td>
<td>🖼️ <b>Screenshot Datastreams</b></td>
<td>☐ ส่งแล้ว</td>
<td>แสดงการตั้งค่า Virtual Pins V0-V6</td>
</tr>
<tr>
<td align="center">5</td>
<td>📊 <b>Screenshot Serial Monitor</b></td>
<td>☐ ส่งแล้ว</td>
<td>แสดงการเชื่อมต่อและข้อมูลที่ส่ง</td>
</tr>
<tr>
<td align="center">6</td>
<td>🎥 <b>วิดีโอการทำงาน (Optional)</b></td>
<td>☐ ส่งแล้ว</td>
<td>แสดงการควบคุม LED และอ่านเซ็นเซอร์</td>
</tr>
</tbody>
</table>

---

## 📊 รายงานผลการทำงาน

### 1️⃣ ข้อมูล Blynk Template

<table>
<tr>
<td width="250"><b>📛 Template Name:</b></td>
<td><code>ESP32S3_[ชื่อของคุณ]</code></td>
</tr>
<tr>
<td><b>🆔 Template ID:</b></td>
<td><code>TMPL_______________</code></td>
</tr>
<tr>
<td><b>🔑 Auth Token:</b></td>
<td><code>____________________________</code></td>
</tr>
<tr>
<td><b>📡 Device Name:</b></td>
<td><code>____________________________</code></td>
</tr>
</table>

### 2️⃣ การต่อวงจร (Hardware Setup)

#### LED Configuration

| LED | GPIO Pin | สีที่ใช้ | ทดสอบแล้ว |
|:---:|:--------:|:-------:|:---------:|
| LED 1 | GPIO 2 | 🔴 _______ | ☐ ทำงานได้ |
| LED 2 | GPIO 4 | 🟡 _______ | ☐ ทำงานได้ |
| LED 3 | GPIO 5 | 🟢 _______ | ☐ ทำงานได้ |

#### Sensor Configuration

| เซ็นเซอร์ | GPIO Pin | ทดสอบแล้ว | ค่าที่วัดได้ (ตัวอย่าง) |
|:--------:|:--------:|:---------:|:---------------------:|
| VR1 | GPIO 6 | ☐ ทำงานได้ | ______ (0-4095) |
| VR2 | GPIO 7 | ☐ ทำงานได้ | ______ (0-4095) |
| MLX90614 SDA | GPIO 8 | ☐ ทำงานได้ | Ambient: _____ °C |
| MLX90614 SCL | GPIO 9 | ☐ ทำงานได้ | Object: _____ °C |

### 3️⃣ การทำงานของระบบ

#### ✅ การควบคุม LED ผ่าน Blynk

- ☐ สวิตช์ SW1 (V0) สามารถควบคุม LED1 ได้
- ☐ สวิตช์ SW2 (V1) สามารถควบคุม LED2 ได้
- ☐ สวิตช์ SW3 (V2) สามารถควบคุม LED3 ได้
- ☐ มี Serial log แสดงสถานะเมื่อเปลี่ยนแปลง

#### 📊 การอ่านค่าเซ็นเซอร์

- ☐ VR1 อ่านค่าได้ถูกต้อง (ส่งไป V3)
- ☐ VR2 อ่านค่าได้ถูกต้อง (ส่งไป V4)
- ☐ MLX90614 อ่านค่า Ambient ได้ (ส่งไป V5)
- ☐ MLX90614 อ่านค่า Object ได้ (ส่งไป V6)
- ☐ ค่าเซ็นเซอร์อัปเดตต่อเนื่อง

#### 🌐 การเชื่อมต่อ Wi-Fi & Blynk

- ☐ เชื่อมต่อ Wi-Fi สำเร็จ
- ☐ แสดง IP Address ใน Serial Monitor
- ☐ เชื่อมต่อ Blynk สำเร็จ
- ☐ แสดง "Ready (ping: ...ms)"
- ☐ มีระบบ auto-reconnect

### 4️⃣ Blynk Dashboard Design

#### Widget Configuration

| Widget | Virtual Pin | ตั้งค่าแล้ว | ทำงานถูกต้อง |
|:------:|:-----------:|:----------:|:-----------:|
| Switch (SW1) | V0 | ☐ | ☐ |
| Switch (SW2) | V1 | ☐ | ☐ |
| Switch (SW3) | V2 | ☐ | ☐ |
| Gauge (VR1) | V3 | ☐ | ☐ |
| Gauge (VR2) | V4 | ☐ | ☐ |
| Gauge (Ambient) | V5 | ☐ | ☐ |
| Gauge (Object) | V6 | ☐ | ☐ |
| Chart (Temp) | V5, V6 | ☐ | ☐ |

---

## 🐛 ปัญหาที่พบและวิธีแก้ไข

<table>
<thead>
<tr>
<th width="50">ลำดับ</th>
<th width="300">ปัญหาที่พบ</th>
<th>วิธีแก้ไข</th>
</tr>
</thead>
<tbody>
<tr>
<td align="center">1</td>
<td>
<textarea rows="2" style="width:100%">
ระบุปัญหาที่พบ (ถ้ามี)
</textarea>
</td>
<td>
<textarea rows="2" style="width:100%">
วิธีที่แก้ไขปัญหา
</textarea>
</td>
</tr>
<tr>
<td align="center">2</td>
<td>
<textarea rows="2" style="width:100%">

</textarea>
</td>
<td>
<textarea rows="2" style="width:100%">

</textarea>
</td>
</tr>
<tr>
<td align="center">3</td>
<td>
<textarea rows="2" style="width:100%">

</textarea>
</td>
<td>
<textarea rows="2" style="width:100%">

</textarea>
</td>
</tr>
</tbody>
</table>

---

## 💭 สิ่งที่ได้เรียนรู้

```
กรุณาเขียนสรุปสิ่งที่ได้เรียนรู้จากการทำโปรเจคนี้ (อย่างน้อย 100 คำ)

ตัวอย่าง:
- ได้เรียนรู้การเชื่อมต่อ ESP32 กับ Blynk Cloud
- เข้าใจการใช้งาน Virtual Pins และ Datastreams
- ฝึกการอ่านค่าเซ็นเซอร์ผ่าน I²C Protocol
- เรียนรู้การออกแบบ Dashboard UI/UX
- พัฒนาทักษะการแก้ไขปัญหา (Debugging)
...







```

---

## 📸 ภาพประกอบ

### 1. รูปถ่ายวงจรจริง

![Hardware Setup](./submissions/[ชื่อของคุณ]_hardware.jpg)

**คำอธิบาย:**
- การต่อสาย: _________________________________
- อุปกรณ์ที่ใช้: _________________________________

### 2. Screenshot Blynk Dashboard

![Blynk Dashboard](./submissions/[ชื่อของคุณ]_dashboard.png)

**คำอธิบาย:**
- Widget ที่ใช้: _________________________________
- Layout: _________________________________

### 3. Screenshot Serial Monitor

![Serial Monitor](./submissions/[ชื่อของคุณ]_serial.png)

**ข้อมูลที่แสดง:**
- การเชื่อมต่อ Wi-Fi: _________________________________
- การเชื่อมต่อ Blynk: _________________________________
- ข้อมูลเซ็นเซอร์: _________________________________

---

## 📊 การประเมินตนเอง

<table>
<thead>
<tr>
<th width="50">หมวด</th>
<th width="300">รายละเอียด</th>
<th width="100">คะแนนเต็ม</th>
<th width="100">คะแนนที่คิดว่าได้</th>
<th>หมายเหตุ</th>
</tr>
</thead>
<tbody>
<tr>
<td align="center"><b>A</b></td>
<td>การต่อวงจรและความเรียบร้อย</td>
<td align="center">4</td>
<td align="center">_____</td>
<td>
<textarea rows="1" style="width:100%"></textarea>
</td>
</tr>
<tr>
<td align="center"><b>B</b></td>
<td>เชื่อมต่อ Wi-Fi & Blynk</td>
<td align="center">2</td>
<td align="center">_____</td>
<td>
<textarea rows="1" style="width:100%"></textarea>
</td>
</tr>
<tr>
<td align="center"><b>C</b></td>
<td>ควบคุม LED ผ่าน Blynk</td>
<td align="center">3</td>
<td align="center">_____</td>
<td>
<textarea rows="1" style="width:100%"></textarea>
</td>
</tr>
<tr>
<td align="center"><b>D</b></td>
<td>อ่าน VR 2 ตัว</td>
<td align="center">2</td>
<td align="center">_____</td>
<td>
<textarea rows="1" style="width:100%"></textarea>
</td>
</tr>
<tr>
<td align="center"><b>E</b></td>
<td>อ่าน MLX90614 (I²C)</td>
<td align="center">2</td>
<td align="center">_____</td>
<td>
<textarea rows="1" style="width:100%"></textarea>
</td>
</tr>
<tr>
<td align="center"><b>F</b></td>
<td>ออกแบบแดชบอร์ด Blynk</td>
<td align="center">2</td>
<td align="center">_____</td>
<td>
<textarea rows="1" style="width:100%"></textarea>
</td>
</tr>
<tr style="background-color: #e8f5e9;">
<td colspan="2" align="center"><b>รวม</b></td>
<td align="center"><b>15</b></td>
<td align="center"><b>_____</b></td>
<td></td>
</tr>
</tbody>
</table>

---

## 📦 วิธีการส่งงาน

### 🎯 ขั้นตอนการส่งงาน:

1. **จัดเตรียมไฟล์**
   - รวบรวมไฟล์ทั้งหมดตาม Checklist
   - ตั้งชื่อไฟล์ให้ถูกต้อง: `ESP32_[ชื่อ]_[ประเภทไฟล์]`

2. **สร้างโฟลเดอร์**
   ```
   ESP32_Blynk_[รหัสนักศึกษา]/
   ├── ESP32_[ชื่อ].ino
   ├── hardware_setup.jpg
   ├── dashboard_screenshot.png
   ├── datastreams_screenshot.png
   ├── serial_monitor.png
   ├── SUBMISSION.md (ไฟล์นี้)
   └── video_demo.mp4 (ถ้ามี)
   ```

3. **บีบอัดไฟล์**
   - สร้างไฟล์ ZIP: `ESP32_Blynk_[รหัสนักศึกษา].zip`
   - ตรวจสอบขนาดไฟล์ (ไม่เกิน 50MB)

4. **ส่งงาน**
   - 📧 **อีเมล**: ส่งไปที่ [อีเมลอาจารย์]
   - 💾 **Google Drive**: แชร์ลิงก์ใน Google Classroom
   - 📱 **LINE**: ส่งใน LINE Group ของวิชา

### ⏰ กำหนดส่งงาน

<table>
<tr style="background-color: #fff3e0;">
<td width="200"><b>📅 วันที่:</b></td>
<td><code>___ / ___ / 2568</code></td>
</tr>
<tr style="background-color: #ffebee;">
<td><b>⏰ เวลา:</b></td>
<td><code>__:__ น.</code></td>
</tr>
<tr style="background-color: #e3f2fd;">
<td><b>🚨 หมายเหตุ:</b></td>
<td><b>ส่งช้าหัก 10% ต่อวัน</b></td>
</tr>
</table>

---

## ✍️ คำรับรองและลายเซ็น

<table>
<tr>
<td width="400">

**ข้าพเจ้าขอรับรองว่า:**
- ☐ ทำงานด้วยตนเองทั้งหมด
- ☐ ไม่ลอกเลียนแบบผู้อื่น
- ☐ ข้อมูลที่ส่งเป็นความจริงทั้งหมด
- ☐ ยินยอมให้อาจารย์ตรวจสอบการทำงาน

</td>
<td align="center">

**ลายเซ็นนักศึกษา**

<br><br><br>

______________________________

**( _________________________ )**

**วันที่:** ____ / ____ / 2568

</td>
</tr>
</table>

---

<div align="center">

## 🎓 ขอให้โชคดีและประสบความสำเร็จ! 🚀

**"Practice makes Perfect"** 💡

---

<sub>แบบฟอร์มนี้จัดทำโดย: อาจารย์ภูริ จันทิมา | ME6831 | ภาคการศึกษา 1/2568</sub>

</div>
