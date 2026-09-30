import struct
with open('flag.enc', 'rb') as f:
    # Read 4 bytes, unpack as Little-Endian (<) Unsigned Integer (I)
    seed = struct.unpack('<I', f.read(4))[0] 
    print(f"The seed is: {seed}")

