from mpi4py import MPI

comm = MPI.COMM_WORLD
rank = comm.Get_rank()

if rank == 0:
    data = {'a': 7, 'b': 3.14}
    a = comm.isend(data, dest=1)
    b = comm.isend(data, dest=2)
    c = comm.isend(data, dest=3)
    a.wait()
    b.wait()
    c.wait()
    print("Master Has Recieved All Data")
elif rank == 1:
    req = comm.irecv(source=0, tag=11)
    data = req.wait()
elif rank == 2:
    req = comm.irecv(source=0, tag=11)
    data = req.wait()
elif rank == 3:
    req = comm.irecv(source=0, tag=11)
    data = req.wait()
