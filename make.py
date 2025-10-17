from docx import Document

# Load the Word document
doc = Document("M08 Final Project InputData.docx")

lines = []

# Loop through all tables and extract text cell by cell
for table in doc.tables:
    for row in table.rows:
        for cell in row.cells:
            text = cell.text.strip()
            if text:
                lines.append(text)

# Skip header (first 3 cells: x-coordinate, Character, y-coordinate)
if lines[0].lower().startswith("x-coordinate"):
    lines = lines[3:]

# Group every 3 lines (x, char, y)
rows = []
for i in range(0, len(lines), 3):
    if i + 2 < len(lines):
        rows.append(f"{lines[i]} {lines[i+1]} {lines[i+2]}")

# Save to input.txt
with open("input.txt", "w", encoding="utf-8") as f:
    f.write("\n".join(rows))

print("✅ Conversion complete! Created 'input.txt' with", len(rows), "entries.")
