import sys
import hashlib 


if len(sys.argv) != 2:
    print("Incorrect number of arguments")
    sys.exit(1)

pw = sys.argv[1]
sha256 = hashlib.sha256()
sha256.update(pw.encode())
hashed = sha256.hexdigest()
print(hashed)
