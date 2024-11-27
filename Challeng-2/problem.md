# Formate Secrets

 - Namespace: picoctf/18739f24
 - ID: formate-secrets
 - Type: custom
 - Category: Binary Exploitation
 - Points: 100
 - Templatable: yes
 - MaxUsers: 1

## Description

If you tell me your top most secret, I will tell you my secret!
It could be flag too...Idk

- `{{url_for("file", "fms")}}` (link to the compiled binary)
- `{{url_for("file", "fms.c")}}` (link to the source code)


## Details

To start the challenge, connect to the remote service using Connect with `nc {{server}} {{port}}`

## Attributes
 - author: sbudayya


## Hints

- format strings

## Tags

- Binary Exploitation
- PicoCTF 2024
- format_string
- medium


