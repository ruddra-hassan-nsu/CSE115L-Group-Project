# Record Design
Photocopy and Print Shop Job Queue

| Field | Type | Available from |
|---|---|---|
| Task ID | `int` | Version 2 |
| Customer name | string (32 `char`) | Version 5 |
| Pages | `int` | Version 2 |
| Copies | `int` | Version 2 |
| Duplex? | boolean | Version 2 |
| Urgent? | boolean | Version 4 |
| Date received | struct Date | Version 6 |

## Derived Values
- Sheets per copy = duplex ? (pages + 1) / 2 : pages
- Total sheets = sheets per copy × copies
- Total cost = total sheets × RATE_PER_SHEET
- Queue position = urgent jobs go ahead of all regular jobs, but not ahead of earlier urgent jobs
