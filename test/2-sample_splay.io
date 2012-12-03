> ./splay
> verbose
> insert 20
< Element inserted
> insert 10
< Element inserted
> insert 2
< Element inserted
> access 2
< Element accessed
> print
< 2 10 20
< 2 10 20
< 2:0(,10:0(,20:0))
> insert 15
< Element inserted
> insert 18
< Element inserted
> insert 12
< Element inserted
> access 15
< Element accessed
> print
< 15 2 10 12 20 18
< 2 10 12 15 18 20
< 15:0(2:0(,10:0(,12:0)),20:0(18:0,))
> delete 10
< Element deleted
> print
< 2 15 12 20 18
< 2 12 15 18 20
< 15:0(2:0(,12:0),20:0(18:0,))
> delete 18
< Element deleted
> print
< 15 2 12 20
< 2 12 15 20
< 15:0(2:0(,12:0),20:0)
> delete 20
< Element deleted
> print
< 15 2 12
< 2 12 15
< 15:0(2:0(,12:0),)
> insert 7
< Element inserted
> print
< 15 2 12 7
< 2 7 12 15
< 15:0(2:0(,12:0(7:0,)),)
