# RISC-V 客製化指令專題 - ABS (絕對值)

**課程名稱**：計算機組織 (Computer Organization)  
**專題主題**：客製化 RISC-V R-type 指令 —— `ABS` (絕對值)  

---

## 專案簡介

本專案旨在為 RISC-V 架構擴充專屬的客製化指令 `ABS`（絕對值）。此指令為一元運算，能直接對 32-bit 有號整數進行絕對值計算，以提升處理器在訊號處理、影像處理與基礎算術運算上的效能。

### 核心規格摘要
- **語意公式**：`rd = |rs1|`
- **指令格式**：R-type (`opcode = 0x0B`, `custom-0`)
- **邊界處理**：當 `rs1 = -2147483648` (`INT32_MIN`) 時，發生 32 位元二補數溢位，依規格 Wrap-around 輸出 `-2147483648`。

---

## 專案目錄結構

本倉庫結構符合課程作業規範 Section 5.2 要求：

```text
ABS/
├── README.md               # 本檔案 (專案總覽說明)
├── CONTRIBUTIONS.md        # 全組個人貢獻與分工聲明
├── instructions/           # 指令規格說明目錄
│   ├── README.md           # 指令目錄說明
│   └── ABS/                # ABS 指令專屬規格與細節
│       └── README.md
├── report/                 # 各 Checkpoint 報告目錄
│   ├── README.md           # 報告目錄說明
│   ├── CP1.md              # CP1 C Baseline 報告
│   └── figures/            # 報告圖表存放區
│       └── README.md
└── src/                    # 程式碼與驗證目錄
    └── c_baseline/         # CP1 C Baseline 原始碼與測試向量
        ├── abs_baseline.c
        └── abs_baseline.h